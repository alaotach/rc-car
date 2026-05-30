#ifndef NAV_H
#define NAV_H

enum class Mode {
    MANUAL,
    AUTONOMOUS,
    REC,
    REPLAY
};

class NavM {
    public:
        static void init();
        static void update();
        static Mode getMode();
        static Mode setMode(Mode mode);
    private:
        static Mode mode;
};

#endif