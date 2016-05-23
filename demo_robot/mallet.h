#include <Servo.h>

#define MALLET_PIN 7

#define MALLET_EXTEND_POS 70
#define MALLET_SNAP_POS 100
#define MALLET_RETRACT_POS 160
#define MALLET_SNAP_DURATION 500
#define MALLET_RETRACT_DURATION 1000

Servo* my_mallet;

void mallet_init(Servo* mallet) {
  my_mallet = mallet;
  (*my_mallet).attach(MALLET_PIN);
  (*my_mallet).write(MALLET_RETRACT_POS);
}

void mallet_swing(void) {
  (*my_mallet).write(MALLET_EXTEND_POS);
  delay(MALLET_SNAP_DURATION);
  (*my_mallet).write(MALLET_SNAP_POS);
}

void mallet_retract(void) {
  (*my_mallet).write(MALLET_RETRACT_POS);
  delay(MALLET_RETRACT_DURATION);
}
