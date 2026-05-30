#ifndef ULTRASONIC_H
#define ULTRASONIC_H
#include <vector>

struct UltrasonicData {
    float left;
    float center;
    float right;
};

class UltrasonicM {
    public:
        static void init();
        static UltrasonicData read();
        static std::vector<bool> isObstacle();
};
#endif