#ifndef GPS_H
#define GPS_H

struct GPSData {
    double lat;
    double lon;
    float speed;
    int numSatellites;
};

class GPSM {
    public:
        static void init();
        static GPSData read();
        static void update();
};
#endif