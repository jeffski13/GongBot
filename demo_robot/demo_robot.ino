#include <DistanceSensor.h>
#include <Servo.h>

#define MOTOR_LEFT_PIN_0 2
#define MOTOR_LEFT_PIN_1 3
#define MOTOR_RIGHT_PIN_0 4
#define MOTOR_RIGHT_PIN_1 5
#define MALLET_PIN 7
#define PING_LEFT_TX_PIN 8
#define PING_LEFT_RX_PIN 9
#define PING_CENTER_TX_PIN 12
#define PING_CENTER_RX_PIN 13
#define PING_RIGHT_TX_PIN 10
#define PING_RIGHT_RX_PIN 11

#define DRIVE_SLOW 100
#define DRIVE_MED  180
#define DRIVE_FAST 230
#define DRIVE_STOP 0

#define MALLET_EXTEND_POS 1800
#define MALLET_RETRACT_POS 1500

Servo mallet;

long left_ping_cm;
long right_ping_cm;
long front_ping_cm;

void setup() {
  pinMode(MOTOR_LEFT_PIN_0, OUTPUT);
  pinMode(MOTOR_LEFT_PIN_1, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN_0, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN_1, OUTPUT);

  mallet.attach(MALLET_PIN);
  
  Serial.begin(9600);
}

void loop() {
  Serial.print("Driving forward at speed: ");
  Serial.println(DRIVE_SLOW, DEC);

  motor_drive_fwd(DRIVE_SLOW);
  //motor_drive_rev(DRIVE_SLOW);
}

//////////////////////////////////////////////////////////////////////////
// MOTOR FUNCTIONS
void motor_drive_fwd(int speed) {
  analogWrite(MOTOR_LEFT_PIN_0, speed);
  analogWrite(MOTOR_LEFT_PIN_1, DRIVE_STOP);

  analogWrite(MOTOR_RIGHT_PIN_0, speed);
  analogWrite(MOTOR_RIGHT_PIN_1, DRIVE_STOP);
}

void motor_drive_rev(int speed) {
  analogWrite(MOTOR_LEFT_PIN_0, DRIVE_STOP);
  analogWrite(MOTOR_LEFT_PIN_1, speed);

  analogWrite(MOTOR_RIGHT_PIN_0, DRIVE_STOP);
  analogWrite(MOTOR_RIGHT_PIN_1, speed);
}

void motor_turn_left(int speed) {
}

void motor_turn_right(int speed) {
}

void motor_rev_left(int speed) {
}

void motor_rev_right(int speed) {
}

//////////////////////////////////////////////////////////////////////////
// MALLET FUNCTIONS
void mallet_swing(void) {
  mallet.write(MALLET_EXTEND_POS);
}

void mallet_retract(void) {
  mallet.write(MALLET_RETRACT_POS);
}

