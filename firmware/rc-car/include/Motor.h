#ifndef MOTOR_H
#define MOTOR_H

class MotorM {
    public:
        static void init();
        static void stop();
        static void forward(int speed);
        static void backward(int speed);
        static void left(int speed);
        static void right(int speed);
};

#endif