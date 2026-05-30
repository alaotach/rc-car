#ifndef ROUTE_H
#define ROUTE_H

#include <vector>

struct Waypoint {
    double lat;
    double lon;
};

class RouteM {
    public:
        static void startRec();
        static void stopRec();
        static void addWaypoint(double lat, double lon);
        static const std::vector<Waypoint>& getRoute();
        static bool isRecording();
private:
        static std::vector<Waypoint> route;
        static bool recording;
};

#endif