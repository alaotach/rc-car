#ifndef ULTRASONIC_H
#define ULTRASONIC_H

struct UltrasonicData {
    float left;
    float center;
    float right;
};

class UltrasonicM {
    public:
        static void init();
        static UltrasonicData read();
};
#endif