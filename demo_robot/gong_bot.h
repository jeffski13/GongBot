// Defines higher-order functions for the robot
#include "motor.h"

#define DANGER_THRESHOLD_CM 5
#define EVADE_REVERSE_DURATION 2000
#define EVADE_PAUSE_DURATION 800
#define STRIKING_DISTANCE_CM 7

enum Danger_Side {
  Danger_Left,
  Danger_Right,
  Danger_Both,
  Danger_None
};

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
  if (left_range_cm > DANGER_THRESHOLD_CM && right_range_cm > DANGER_THRESHOLD_CM) {
    return Danger_Both;
  } else if (left_range_cm > DANGER_THRESHOLD_CM) {
    return Danger_Left;
  } else if (right_range_cm > DANGER_THRESHOLD_CM) {
    return Danger_Right;
  }

  return Danger_None;
}

bool gong_is_detected(long center_range_cm) {
  if (center_range_cm <= STRIKING_DISTANCE_CM) {
    return true;
  }

  return false;
}

