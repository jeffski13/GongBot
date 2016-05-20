#include <DistanceSensor.h>
#include <Servo.h>

#define MOTOR_LEFT_PIN_0 10
#define MOTOR_LEFT_PIN_1 11
#define MOTOR_RIGHT_PIN_0 5
#define MOTOR_RIGHT_PIN_1 6
#define MALLET_PIN 7
#define PING_LEFT_TX_PIN 9
#define PING_LEFT_RX_PIN 8
#define PING_CENTER_TX_PIN 12
#define PING_CENTER_RX_PIN 13
#define PING_RIGHT_TX_PIN 3
#define PING_RIGHT_RX_PIN 2

#define DRIVE_SLOW 100
#define DRIVE_MED  180
#define DRIVE_FAST 230
#define DRIVE_STOP 0

#define MALLET_EXTEND_POS 70
#define MALLET_SNAP_POS 100
#define MALLET_RETRACT_POS 160

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
  mallet.write(MALLET_RETRACT_POS);
  delay(2000);

  mallet_swing();

  delay(2000);
  mallet.write(MALLET_RETRACT_POS);
  
  Serial.begin(9600);
}

void loop() {
  Serial.print("Driving forward at speed: ");
  Serial.println(DRIVE_SLOW, DEC);

  //motor_drive_fwd(DRIVE_SLOW);
  //motor_drive_rev(DRIVE_SLOW);
  //mallet_swing();
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
  delay(500);
  mallet.write(MALLET_SNAP_POS);
}

void mallet_retract(void) {
  mallet.write(MALLET_RETRACT_POS);
}

