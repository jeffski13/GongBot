/*
 * file: motor.h
 * created: 20160522
 * author(s): mr-augustine
 * 
 * Defines the Arduino pins, initialization function, and basic functions for the DC motors
 * used to move the robot.
 */
 
#define MOTOR_LEFT_PIN_0          6
#define MOTOR_LEFT_PIN_1          11
#define MOTOR_RIGHT_PIN_0         5
#define MOTOR_RIGHT_PIN_1         3

#define RIGHT_MOTOR_FUDGE_FWD     35
#define RIGHT_MOTOR_FUDGE_REV     35
#define RIGHT_MOTOR_TURN_FUDGE    40

// TODO Tune these drive values
#define DRIVE_SLOW                100
#define DRIVE_MED                 180
#define DRIVE_FAST                230
#define DRIVE_STOP                0

// Lists the different types of turns the motors can be commanded to make
typedef enum {
  Turn_Angle_Small,
  Turn_Angle_Med,
  Turn_Angle_Large
} Turn_Angle;

// Lists the directions that the motors can be commanded to turn to robot
typedef enum {
  Direction_Left,
  Direction_Right
} Direction;

/*
 * Initializes the robot's motors by configuring the motor pins as output pins 
 */
void motor_init(void) {
  pinMode(MOTOR_LEFT_PIN_0, OUTPUT);
  pinMode(MOTOR_LEFT_PIN_1, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN_0, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN_1, OUTPUT);
}

/*
 * Commands the robot to drive forward at a given speed, which is expressed as a value 
 * between 0 and 255.
 */
void motor_drive_fwd(int speed) {
  analogWrite(MOTOR_LEFT_PIN_0, speed + RIGHT_MOTOR_FUDGE_FWD);
  analogWrite(MOTOR_LEFT_PIN_1, DRIVE_STOP);

  analogWrite(MOTOR_RIGHT_PIN_0, speed);
  analogWrite(MOTOR_RIGHT_PIN_1, DRIVE_STOP);
}

/*
 * Commands the robot to drive in reverse at a given speed, which is expressed as a value 
 * between 0 and 255.
 */
void motor_drive_rev(int speed) {
  analogWrite(MOTOR_LEFT_PIN_0, DRIVE_STOP);
  analogWrite(MOTOR_LEFT_PIN_1, speed + RIGHT_MOTOR_FUDGE_REV);

  analogWrite(MOTOR_RIGHT_PIN_0, DRIVE_STOP);
  analogWrite(MOTOR_RIGHT_PIN_1, speed);
}

/*
 * Commands the robot to stop driving.
 */
void motor_stop(void) {
  analogWrite(MOTOR_LEFT_PIN_0, DRIVE_STOP);
  analogWrite(MOTOR_LEFT_PIN_1, DRIVE_STOP);
  analogWrite(MOTOR_RIGHT_PIN_0, DRIVE_STOP);
  analogWrite(MOTOR_RIGHT_PIN_1, DRIVE_STOP);
}

/*
 * Commands the robot to turn in a particular direction, by a general degree, and at a specific
 * speed.
 */
void motor_pivot(Direction dir, Turn_Angle angle, int speed) {
  motor_stop();

  if (dir == Direction_Left) {
    // Command the right wheel to turn left
    analogWrite(MOTOR_RIGHT_PIN_0, speed + RIGHT_MOTOR_TURN_FUDGE);
    analogWrite(MOTOR_RIGHT_PIN_1, DRIVE_STOP);     
  } else {
    // Command the left wheel to turn right
    analogWrite(MOTOR_LEFT_PIN_0, speed);
    analogWrite(MOTOR_LEFT_PIN_1, DRIVE_STOP);   
  }

  // Keep turning until a big enough turn is reached 
  int turn_delay = 0;
  
  switch (angle) {
    case Turn_Angle_Small:
      turn_delay = 1000;
      break;
     case Turn_Angle_Med:
      turn_delay = 1600;
      break;
     case Turn_Angle_Large:
      turn_delay = 2600;
      break;
     default:
      turn_delay = 500;
  }

  delay(turn_delay);

  // Stop the motors when finished turning
  motor_stop();
}


