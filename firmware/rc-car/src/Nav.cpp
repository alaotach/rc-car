#include "Nav.h"
#include "Route.h"
#include "Ultrasonic.h"
#include "Gps.h"
#include "IMU.h"
#include "Motor.h"
#include <vector>
#include <cmath>

Mode NavM::mode = Mode::MANUAL;

static size_t routeIndex = 0;

static double calcDist(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371e3; // Earth radius in meters
    double phi1 = lat1 * M_PI / 180;
    double phi2 = lat2 * M_PI / 180;
    double deltaPhi = (lat2 - lat1) * M_PI / 180;
    double deltaLambda = (lon2 - lon1) * M_PI / 180;

    double a = sin(deltaPhi/2) * sin(deltaPhi/2) +
               cos(phi1) * cos(phi2) *
               sin(deltaLambda/2) * sin(deltaLambda/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    return R * c;
}

static double calcBearing(double lat1, double lon1, double lat2, double lon2) {
    double phi1 = lat1 * M_PI / 180;
    double phi2 = lat2 * M_PI / 180;
    double deltaLambda = (lon2 - lon1) * M_PI / 180;

    double y = sin(deltaLambda) * cos(phi2);
    double x = cos(phi1) * sin(phi2) -
               sin(phi1) * cos(phi2) * cos(deltaLambda);
    return atan2(y, x) * 180 / M_PI;
}

void NavM::init() {
    RouteM::startRec();
}

Mode NavM::setMode(Mode newMode) {
    if (mode == Mode::REC && newMode != Mode::REC) {
        RouteM::stopRec();
    }
    mode = newMode;
    return mode;
}

Mode NavM::getMode() {
    return mode;
}

static void avoid() {
    auto data = UltrasonicM::read();
    if (data.center < 25) {
        MotorM::backward(150);
    } else if (data.left < 25) {
        MotorM::right(150);
    } else if (data.right < 25) {
        MotorM::left(150);
    } else {
        MotorM::forward(150);
    }
}

void NavM::update() {
    if (mode==Mode::MANUAL) {
        return;
    }
    auto gps = GPSM::read();
    if (mode == Mode::REC) {
        RouteM::addWaypoint(gps.lat, gps.lon);
        return;
    }
    if (mode == Mode::AUTONOMOUS){
        avoid();
        MotorM::forward(150); // implement gps later
        return;
    }
    if (mode == Mode::REPLAY) {
        return;
    }
    avoid();
    auto target = RouteM::getRoute()[routeIndex];
    double dist = calcDist(gps.lat, gps.lon, target.lat, target.lon);
    if (dist < 10) {
        routeIndex++;
    } else {
        double angle = atan2(target.lat - gps.lat, target.lon - gps.lon);
        double headingDiff = angle - IMUM::getHeading();
        headingDiff = atan2(sin(headingDiff), cos(headingDiff));

        if (abs(headingDiff) < M_PI / 18) { // within 10 degrees
            MotorM::forward(150);
        } else if (headingDiff > 0) {
            MotorM::right(50);
        } else {
            MotorM::left(50);
        }

        double bearing = calcBearing(gps.lat, gps.lon, target.lat, target.lon);
        if (bearing > 0) {
            MotorM::right(50);
        } else {
            MotorM::left(50);
        }
        if (dist < 50) {
            MotorM::forward(100);
        } else if (dist < 100) {
            MotorM::forward(150);
        } else {
            MotorM::forward(200);
        }
    }