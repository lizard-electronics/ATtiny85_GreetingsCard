#ifndef _BUZZER_DRIVER_H_
#define _BUZZER_DRIVER_H_

#include <Arduino.h>
#include <system_hardware.h>

/***************************************
// Melody Notes
***************************************/
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784

/***************************************
// Melodies
***************************************/
struct MelodyNote {
  uint16_t notes;
  uint8_t tempo;
};
extern const MelodyNote jingleBells[];

extern bool play_melody;

/***************************************
// Function Declarations
***************************************/
void PlayMelody();

#endif