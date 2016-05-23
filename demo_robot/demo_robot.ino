#include <DistanceSensor.h>
#include <Servo.h>

#include "motor.h"

#define MALLET_PIN 7
#define PING_LEFT_TRIG_PIN 9
#define PING_LEFT_ECHO_PIN 8
#define PING_CENTER_TRIG_PIN 12
#define PING_CENTER_ECHO_PIN 13
#define PING_RIGHT_TRIG_PIN 3
#define PING_RIGHT_ECHO_PIN 2

#define MALLET_EXTEND_POS 70
#define MALLET_SNAP_POS 100
#define MALLET_RETRACT_POS 160

Servo mallet;

long left_ping_cm;
long right_ping_cm;
long center_ping_cm;

DistanceSensor left_ping(PING_LEFT_TRIG_PIN, PING_LEFT_ECHO_PIN);
DistanceSensor right_ping(PING_RIGHT_TRIG_PIN, PING_RIGHT_ECHO_PIN);
DistanceSensor center_ping(PING_CENTER_TRIG_PIN, PING_CENTER_ECHO_PIN);

void setup() {
  pinMode(MOTOR_LEFT_PIN_0, OUTPUT);
  pinMode(MOTOR_LEFT_PIN_1, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN_0, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN_1, OUTPUT);
  
  //mallet.attach(MALLET_PIN);
    
  Serial.begin(9600);

  // Wait a little while, then start driving forward
  delay(2000);
  //motor_drive_fwd(DRIVE_SLOW);
  motor_pivot(Direction_Left, Turn_Angle_Large, DRIVE_SLOW);

  while(1) {}
}

void loop() {
  //Serial.print("Driving forward at speed: ");
  //Serial.println(DRIVE_SLOW, DEC);

  //motor_drive_fwd(DRIVE_SLOW);
  //motor_drive_rev(DRIVE_SLOW);
  //mallet_swing();

  left_ping_cm = left_ping.getDistance(true);
  right_ping_cm = right_ping.getDistance(true);
  center_ping_cm = center_ping.getDistance(true);
  //Serial.print("Left Distance: ");
  //Serial.println(left_ping_cm, DEC);
  //Serial.print("  Center Distance: ");
  //Serial.println(center_ping_cm, DEC);
  //Serial.print("  Right Distance: ");
  //Serial.println(right_ping_cm, DEC);

  return;

  // 1 - Get the latest ping sensor readings

  // 2 - Check if an edge was detected
  // 2.1 - If edge on the right, then reverse, turn left, then continue
  // 2.2 - Else if edge on the left, then reverse, turn right, then continue
  // 2.3 - Else (if both) then reverse, turn either right or left, then continue

  // 3 - Check if an obstacle was detected
  // 3.1 - If and obstacle is withing striking distance, then: stop, swing the mallet,
  //        retract the mallet, wait, reverse and turn as if an edge was detected on both sensors
  // 3.2 - Else keep moving forward (continue)
}

//////////////////////////////////////////////////////////////////////////
// MALLET FUNCTIONS
void mallet_swing(void) {
  mallet.write(MALLET_EXTEND_POS);
  delay(500);
  mallet.write(MALLET_SNAP_POS);

  /*mallet.write(MALLET_RETRACT_POS);
  delay(2000);

  mallet_swing();

  delay(2000);
  mallet.write(MALLET_RETRACT_POS);*/
}

void mallet_retract(void) {
  mallet.write(MALLET_RETRACT_POS);
  delay(1000);
}

//////////////////////////////////////////////////////////////////////////
// MANEUVER FUNCTIONS
void evade_edge(int danger_side) {
}


