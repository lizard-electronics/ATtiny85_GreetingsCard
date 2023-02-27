#ifndef STATEMACHINE_ACTIONS_H
#define STATEMACHINE_ACTIONS_H

//--------------------------------------
//-- States for State Machine
//--------------------------------------
typedef enum {
  IDLE,
  ANIMATION_1,
  ANIMATION_2,
  ANIMATION_3,
  MELODY
} machine_sate_t;

//--------------------------------------
//-- Declarations
//--------------------------------------
extern machine_sate_t state;

machine_sate_t doIdle();
machine_sate_t doAnimation1();
machine_sate_t doAnimation2();
machine_sate_t doAnimation3();
machine_sate_t doMelody();

#endif