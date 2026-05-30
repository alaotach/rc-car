#include <Arduino.h>
#include "Motor.h"
#include "Config.h"

static int speed = 0;

void MotorM::init() {
  pinMode(MOTORAIN1, OUTPUT);
  pinMode(MOTORAIN2, OUTPUT);
  pinMode(MOTORBIN1, OUTPUT);
  pinMode(MOTORBIN2, OUTPUT);
  pinMode(MOTORPWMA, OUTPUT);
  pinMode(MOTORPWMB, OUTPUT);
  ledcAttachPin(MOTORPWMA, 0);
  ledcAttachPin(MOTORPWMB, 1);
  MotorM::stop();
}

void MotorM::stop() {
  digitalWrite(MOTORAIN1, LOW);
  digitalWrite(MOTORAIN2, LOW);
  digitalWrite(MOTORBIN1, LOW);
  digitalWrite(MOTORBIN2, LOW);
  ledcWrite(0, 0);
  ledcWrite(1, 0);
}

void MotorM::forward(int speed) {
  digitalWrite(MOTORAIN1, HIGH);
  digitalWrite(MOTORAIN2, LOW);
  digitalWrite(MOTORBIN1, HIGH);
  digitalWrite(MOTORBIN2, LOW);
  ledcWrite(0, speed);
  ledcWrite(1, speed);
}

void MotorM::backward(int speed) {
  digitalWrite(MOTORAIN1, LOW);
  digitalWrite(MOTORAIN2, HIGH);
  digitalWrite(MOTORBIN1, LOW);
  digitalWrite(MOTORBIN2, HIGH);
  ledcWrite(0, speed);
  ledcWrite(1, speed);
}

void MotorM::left(int speed) {
  digitalWrite(MOTORAIN1, LOW);
  digitalWrite(MOTORAIN2, HIGH);
  digitalWrite(MOTORBIN1, HIGH);
  digitalWrite(MOTORBIN2, LOW);
  ledcWrite(0, speed);
  ledcWrite(1, speed);
}

void MotorM::right(int speed) {
  digitalWrite(MOTORAIN1, HIGH);
  digitalWrite(MOTORAIN2, LOW);
  digitalWrite(MOTORBIN1, LOW);
  digitalWrite(MOTORBIN2, HIGH);
  ledcWrite(0, speed);
  ledcWrite(1, speed);
}