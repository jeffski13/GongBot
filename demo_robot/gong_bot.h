// Defines higher-order functions for the robot
#include "motor.h"
#include "mallet.h"
#include "ping.h"

#define DANGER_THRESHOLD_CM 5
#define EVADE_REVERSE_DURATION 2000
#define EVADE_PAUSE_DURATION 800
#define GONG_PAUSE_DURATION 2000
#define STRIKING_DISTANCE_CM 7
#define MAX_RANGE_FLAG 0

enum Danger_Side {
  Danger_Left,
  Danger_Right,
  Danger_Both,
  Danger_None
};

//Servo mallet;

void evade_edge(Danger_Side danger_side) {
  motor_stop();
  motor_drive_rev(DRIVE_SLOW);
  delay(EVADE_REVERSE_DURATION);
  
  motor_stop();
  delay(EVADE_PAUSE_DURATION);
    
  switch (danger_side) {
    case Danger_Left:
      motor_pivot(Direction_Right, Turn_Angle_Med, DRIVE_MED);
      break;
    case Danger_Right:
      motor_pivot(Direction_Left, Turn_Angle_Med, DRIVE_MED);
      break;
    case Danger_Both:
      motor_pivot(Direction_Left, Turn_Angle_Large, DRIVE_MED);
      break;
    default:
      // This is for the Danger_None case, which should not occur.
      // Nothing should be performed here.
      ;
  }

  motor_stop();
  delay(EVADE_PAUSE_DURATION);
}

Danger_Side assess_danger(long left_range_cm, long right_range_cm) {
  if (edge_is_detected(left_range_cm) && edge_is_detected(right_range_cm)) {
    return Danger_Both;
  } else if (edge_is_detected(left_range_cm)) {
    return Danger_Left;
  } else if (edge_is_detected(right_range_cm)) {
    return Danger_Right;
  }

  return Danger_None;
}

bool edge_detected(long range) {
  // Note: When the ping sensor's max range limit is reached, it returns a range of 0 (i.e. MAX_RANGE_FLAG)
  if (range > DANGER_THRESHOLD_CM || range == MAX_RANGE_FLAG) {
    return true;
  }

  return false;
}

bool gong_detected(long center_range_cm) {
  if (center_range_cm <= STRIKING_DISTANCE_CM) {
    return true;
  }

  return false;
}

void gong() {
  motor_stop();
  mallet_swing();
  mallet_retract();

  delay(GONG_PAUSE_DURATION);
  
  evade_edge(Danger_Both);
}

void ping_update_all(void) {
  *left_range_ptr = left_ping_ptr->getDistance(true);
  *center_range_ptr = center_ping_ptr->getDistance(true);
  *right_range_ptr = right_ping_ptr->getDistance(true);
}

