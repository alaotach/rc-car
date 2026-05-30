#include <Wire.h>
#include "IMU.h"

static IMUData imuData;

void IMUM::init() {
    Wire.begin(0x68);
    Wire.beginTransmission(0x68);
    Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission(true);
}

void IMUM::upadte() {
    Wire.beginTransmission(0x68);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(0x68, 6, true);
    imuData.pitch = (Wire.read() << 8 | Wire.read()) / 16384.0 * 90;
    imuData.roll = (Wire.read() << 8 | Wire.read()) / 16384.0 * 90;
    imuData.yaw = (Wire.read() << 8 | Wire.read()) / 131.0;
}

IMUData IMUM::read() {
    return imuData;
}


double IMUM::getHeading() {
    return imuData.yaw;
}