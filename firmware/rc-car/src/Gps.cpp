#include <Arduino.h>
#include "Gps.h"
#include "Config.h"
#include <TinyGPS++.h>

static TinyGPSPlus gps;
static HardwareSerial gpsSerial(1);

static GPSData gpsData;

void GPSM::init() {
  gpsSerial.begin(9600, SERIAL_8N1, GPS_RX, GPS_TX);
}

void GPSM::update() {
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }
  if (gps.location.isValid()) {
    gpsData.lat = gps.location.lat();
    gpsData.lon = gps.location.lng();
  }
    if (gps.speed.isValid()) {
        gpsData.speed = gps.speed.kmph();
    }
    if (gps.satellites.isValid()) {
        gpsData.numSatellites = gps.satellites.value();
    }
}

GPSData GPSM::read() {
    return gpsData;
}