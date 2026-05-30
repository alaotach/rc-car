#include "Route.h"
#include "Ultrasonic.h"

bool RouteM::recording = false;
std::vector<Waypoint> RouteM::route;

void RouteM::startRec() {
    recording = true;
    route.clear();
}

void RouteM::stopRec() {
    recording = false;
}

bool RouteM::isRecording() {
    return recording;
}

void RouteM::addWaypoint(double lat, double lon) {
    if (recording) {
        route.push_back({lat, lon});
    }
}

const std::vector<Waypoint>& RouteM::getRoute() {
    return route;
}
