#include <DistanceSensor.h>

#include "gong_bot.h"

Servo mallet;

DistanceSensor left_ping(PING_LEFT_TRIG_PIN, PING_LEFT_ECHO_PIN);
DistanceSensor right_ping(PING_RIGHT_TRIG_PIN, PING_RIGHT_ECHO_PIN);
DistanceSensor center_ping(PING_CENTER_TRIG_PIN, PING_CENTER_ECHO_PIN);

long left_ping_cm;
long right_ping_cm;
long center_ping_cm;

void setup() {
  motor_init();
  mallet_init(&mallet);
  ping_init(&left_ping, &left_ping_cm, &center_ping, &center_ping_cm, &right_ping, &right_ping_cm);
    
  Serial.begin(9600);

  // Wait a little while, then start driving forward
  delay(2000);
  //motor_drive_fwd(DRIVE_SLOW);
  
  //while(1) {}
}

void loop() {
  ping_update_all();

  /*left_ping_cm = left_ping.getDistance(true);
  right_ping_cm = right_ping.getDistance(true);
  center_ping_cm = center_ping.getDistance(true);*/
  Serial.print("Left Distance: ");
  Serial.println(left_ping_cm, DEC);
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
  // 3.1 - If and obstacle is within striking distance, then: stop, swing the mallet,
  //        retract the mallet, wait, reverse and turn as if an edge was detected on both sensors
  // 3.2 - Else keep moving forward (continue)
}

