/*
 * file: demo_robot.h
 * created: 20160519
 * author(s): mr-augustine, jeffski13
 * 
 * This file exercises GongBot's functions to demonstrate its capabilities.
 */
 
#include "gong_bot.h"

Servo mallet;

DistanceSensor left_ping(PING_LEFT_TRIG_PIN, PING_LEFT_ECHO_PIN);
DistanceSensor right_ping(PING_RIGHT_TRIG_PIN, PING_RIGHT_ECHO_PIN);
DistanceSensor center_ping(PING_CENTER_TRIG_PIN, PING_CENTER_ECHO_PIN);

long left_ping_cm;
long right_ping_cm;
long center_ping_cm;

Danger_Side edge_alert;

void setup() {
  // Initialize all of the components
  motor_init();
  mallet_init(&mallet);
  ping_init(&left_ping, &left_ping_cm, &center_ping, &center_ping_cm, &right_ping, &right_ping_cm);
  
  // Enable the Serial port in case we want to do debug printing  
  Serial.begin(9600);

  // Wait a little while, then start driving forward
  delay(2000);
  //motor_drive_fwd(DRIVE_SLOW);
  motor_drive_rev(DRIVE_SLOW);
  //mallet_swing();
  //gong();
  //mallet.write(90);
  //analogWrite(MOTOR_RIGHT_PIN_0, 80);
  //analogWrite(MOTOR_RIGHT_PIN_1, 0);
  while(1) {}
}

void loop() {
  
  // 1 - Get the latest ping sensor readings
  ping_update_all();
  
  // 2 - Check if an edge was detected
  edge_alert = assess_danger(left_ping_cm, right_ping_cm);

  if (edge_alert != Danger_None) {
    evade_edge(edge_alert);
  }

  // 3 - Check if an obstacle was detected
  /*if (gong_detected(center_ping_cm)) {
    gong();
  }*/

  motor_drive_fwd(DRIVE_SLOW);
}

