#include <Arduino.h>
#include "Ultrasonic.h"
#include "Config.h"
#include <vector>

static float distance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return (duration * 0.0343) / 2;
}

void UltrasonicM::init() {
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(TRIG3, OUTPUT);
  pinMode(ECHO3, INPUT);
}

UltrasonicData UltrasonicM::read() {
  UltrasonicData data;
  data.left = distance(TRIG1, ECHO1);
  data.center = distance(TRIG2, ECHO2);
  data.right = distance(TRIG3, ECHO3);
  return data;
}

std::vector<bool> UltrasonicM::isObstacle() {
  UltrasonicData data = read();
  return {
    data.left < 25,
    data.center < 25,
    data.right < 25
  };
}