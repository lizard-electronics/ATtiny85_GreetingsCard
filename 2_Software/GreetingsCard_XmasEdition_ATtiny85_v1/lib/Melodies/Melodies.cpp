#include <Arduino.h>
#include "Melodies.h"
#include "SystemHardware.h"

void weWishYouMerryXmas() {
  // Melody notes
  int jingleBells_Notes[] = {
    NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
    NOTE_E5,
    NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
    NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
    NOTE_D5, NOTE_G5
  };

  // Note duration: (value)^-1
  int jingleBells_Tempo[] = {
    4, 4, 2,
    4, 4, 2,
    4, 4, 4, 4,
    1,
    4, 4, 4, 4,
    4, 4, 4, 8, 8,
    4, 4, 4, 4,
    2, 2
  };

	int size = sizeof(jingleBells_Notes) / sizeof(int);
	for (int thisNote = 0; thisNote < size; thisNote++) {
		// To calculate the note duration, take one second
		// divided by the note type.
		// [i.e.] quarter note = 1000 / 4, eighth note = 1000/8, etc.
		int noteDuration = 1000 / jingleBells_Tempo[thisNote];

		tone(TONE_PIN, jingleBells_Notes[thisNote], noteDuration);

		// Set a minimum time between notes to distinguish them.
		// [recommended] note's duration + 30%
		int pauseBetweenNotes = noteDuration * 1.30;
		delay(pauseBetweenNotes);

		// Stops the tone playing
		tone(TONE_PIN, 0, noteDuration);
	}
}