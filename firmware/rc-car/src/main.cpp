#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <Wire.h>
#include <esp_camera.h>
#include "Config.h"
#include "Web.h"
#include "Nav.h"
#include "Gps.h"
#include "IMU.h"
#include "Motor.h"
#include "Camera.h"

void setup() {
    Serial.begin(115200);
    Wire.begin();
    GPSM::init();
    IMUM::init();
    MotorM::init();
    CameraM::init();
    WebM::init();
    NavM::init();
    xTaskCreatePinnedToCore(navTask, "nav", 4096, nullptr, 1, nullptr, 1);
    xTaskCreatePinnedToCore(gpsTask, "gps", 4096, nullptr, 1, nullptr, 1);
    xTaskCreatePinnedToCore(imuTask, "imu", 4096, nullptr, 1, nullptr, 1);
    Serial.println("Setup done");
}

void navTask(void*){
  while(true){
    NavM::update();
  }
}

void gpsTask(void*){
  while(true){
    GPSM::update();
  }
}


void imuTask(void*){
  while(true){
    IMUM::update();
  }
}
void loop() {
  delay(2000);
}
