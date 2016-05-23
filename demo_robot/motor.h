#define MOTOR_LEFT_PIN_0 5
#define MOTOR_LEFT_PIN_1 6
#define MOTOR_RIGHT_PIN_0 11
#define MOTOR_RIGHT_PIN_1 10

#define DRIVE_SLOW 100
#define DRIVE_MED  180
#define DRIVE_FAST 230
#define DRIVE_STOP 0

enum Turn_Angle {
  Turn_Angle_Small,
  Turn_Angle_Med,
  Turn_Angle_Large
};

enum Direction {
  Direction_Left,
  Direction_Right
};

void motor_init(void) {
  pinMode(MOTOR_LEFT_PIN_0, OUTPUT);
  pinMode(MOTOR_LEFT_PIN_1, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN_0, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN_1, OUTPUT);
}

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

void motor_stop(void) {
  analogWrite(MOTOR_LEFT_PIN_0, DRIVE_STOP);
  analogWrite(MOTOR_LEFT_PIN_1, DRIVE_STOP);
  analogWrite(MOTOR_RIGHT_PIN_0, DRIVE_STOP);
  analogWrite(MOTOR_RIGHT_PIN_1, DRIVE_STOP);
}

void motor_pivot(enum Direction dir, enum Turn_Angle angle, int speed) {
  motor_stop();

  if (dir == Direction_Left) {
    analogWrite(MOTOR_RIGHT_PIN_0, speed);
    analogWrite(MOTOR_RIGHT_PIN_1, DRIVE_STOP);     
  } else {
    analogWrite(MOTOR_LEFT_PIN_0, speed);
    analogWrite(MOTOR_LEFT_PIN_1, DRIVE_STOP);   
  }
  
  int turn_delay = 0;
  
  switch (angle) {
    case Turn_Angle_Small:
      turn_delay = 1000;
      break;
     case Turn_Angle_Med:
      turn_delay = 2000;
      break;
     case Turn_Angle_Large:
      turn_delay = 4000;
      break;
     default:
      turn_delay = 500;
  }

  delay(turn_delay);

  motor_stop();
}

