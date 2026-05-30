#include "Nav.h"
#include "Web.h"
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "Config.h"
#include "Gps.h"
#include "IMU.h"
#include "Motor.h"

static AsyncWebServer server(80);
static AsyncWebSocket ws("/ws");

static void processCmd(const String& cmd) {
    if (cmd == "f"){
        MotorM::forward(180);
    } else if (cmd == "b") {
        MotorM::backward(180);
    } else if (cmd == "l") {
        MotorM::left(180);
    } else if (cmd == "r") {
        MotorM::right(180);
    }
    else if (cmd == "s") {
        MotorM::stop();
    } else if (cmd == "a") {
        NavM::setMode(Mode::AUTONOMOUS);
    } else if (cmd == "m") {
        NavM::setMode(Mode::MANUAL);
    } else if (cmd == "rec") {
        NavM::setMode(Mode::REC);
    } else if (cmd == "replay") {
        NavM::setMode(Mode::REPLAY);
    }
}

static void handleWS(void*, uint8_t* data, size_t len) {
    String cmd = String((char*)data);
    cmd.trim();
    processCmd(cmd);
}

void WebM::init() {
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    ws.onEvent([](
        AsyncWebSocket* server, AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len
    ) {
        if (type == WS_EVT_DATA) {
            handleWS(arg, data, len);
        }
    });
    server.addHandler(&ws);
    server.on("/telemetry", HTTP_GET, [](AsyncWebServerRequest* request) {
        JsonDocument doc;
        auto gps = GPSM::read();
        auto imu = IMUM::read();
        doc["lat"] = gps.lat;
        doc["lon"] = gps.lon;
        doc["speed"] = gps.speed;
        doc["sat"] = gps.numSatellites;
        doc["heading"] = imu.yaw;
        String out;
        serializeJson(doc, out);
        request->send(200, "application/json", out);
    });
    server.begin();
}