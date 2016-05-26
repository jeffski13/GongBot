
/*
 * file: ping.h
 * created: 20160523
 * author(s): mr-augustine
 * 
 * Defines the Arduino pins and initialization function for the three ultrasonic sensors --
 * left, center, and right.
 */
 
#include <DistanceSensor.h>

#define PING_LEFT_TRIG_PIN        9
#define PING_LEFT_ECHO_PIN        8

#define PING_CENTER_TRIG_PIN      12
#define PING_CENTER_ECHO_PIN      13

#define PING_RIGHT_TRIG_PIN       4
#define PING_RIGHT_ECHO_PIN       2

DistanceSensor* left_ping_ptr;
DistanceSensor* center_ping_ptr;
DistanceSensor* right_ping_ptr;

long* left_range_ptr;
long* center_range_ptr;
long* right_range_ptr;

/*
 * Initializes the ping sensors by storing references to the sensors and the variables that
 * store their measured distances. This allows us to create wrapper functions that operate
 * on all sensors at once.
 */
void ping_init(DistanceSensor* left, long* left_distance,
              DistanceSensor* center, long* center_distance,
              DistanceSensor* right, long* right_distance) {
  left_ping_ptr = left;
  left_range_ptr = left_distance;
  
  center_ping_ptr = center;
  center_range_ptr = center_distance;
  
  right_ping_ptr = right;
  right_range_ptr = right_distance;
}

