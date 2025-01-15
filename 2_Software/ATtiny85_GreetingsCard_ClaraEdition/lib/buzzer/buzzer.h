#ifndef _BUZZER_H
#define _BUZZER_H

#include <Arduino.h>
#include <system_hardware.h>

// Frequências das notas musicais (em Hz)
extern const int NOTE_C4;
extern const int NOTE_E4;
extern const int NOTE_G4;
extern const int NOTE_FEEDBACK;

// Funções para efeitos sonoros
void playTone(int frequency, int duration);
void playStartupSound();
void playButtonFeedback();
void playGameOver();
void playVictory();

#endif