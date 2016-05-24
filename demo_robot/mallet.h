/*
 * file: mallet.h
 * created: 20160523
 * author(s): mr-augustine
 * 
 * Defines the Arduino pins, initialization function, and basic functions for the servo
 * used to swing the mallet.
 */
 
#include <Servo.h>

#define MALLET_PIN                7

#define MALLET_EXTEND_POS         90
#define MALLET_SNAP_POS           60
#define MALLET_RETRACT_POS        10
#define MALLET_SNAP_DURATION      200
#define MALLET_RETRACT_DURATION   1000

Servo* my_mallet;

/*
 * Initializes the mallet servo by associating the servo's PWM line with an Arduino pin,
 * and then commands the servo to move to its starting position.
 */
void mallet_init(Servo* mallet) {
  my_mallet = mallet;
  my_mallet->attach(MALLET_PIN);
  my_mallet->write(MALLET_RETRACT_POS);
}

/*
 * Commands the robot to swing the mallet.
 */
void mallet_swing(void) {
  my_mallet->write(MALLET_EXTEND_POS);
  delay(MALLET_SNAP_DURATION);
  my_mallet->write(MALLET_SNAP_POS);
}

/*
 * Commands the robot to move the mallet to its starting position.
 */
void mallet_retract(void) {
  my_mallet->write(MALLET_RETRACT_POS);
  delay(MALLET_RETRACT_DURATION);
}
