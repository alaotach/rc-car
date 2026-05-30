#ifndef IMU_H
#define IMU_H

struct IMUData {
    float yaw;
    float pitch;
    float roll;
};

class IMUM {
    public:
        static void init();
        static IMUData read();
        static void upadte();
};

#endif