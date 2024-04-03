#include <buzzer_driver.h>
#include <avr/pgmspace.h>

bool play_melody = false;

/***************************************
// Melodies
***************************************/
const MelodyNote jingleBells[] = {
  {NOTE_E5, 4}, {NOTE_E5, 4}, {NOTE_E5, 2},
  {NOTE_E5, 4}, {NOTE_E5, 4}, {NOTE_E5, 2},
  {NOTE_E5, 4}, {NOTE_G5, 4}, {NOTE_C5, 4}, {NOTE_D5, 4},
  {NOTE_E5, 2},
  {NOTE_F5, 4}, {NOTE_F5, 4}, {NOTE_F5, 4}, {NOTE_F5, 4},
  {NOTE_F5, 4}, {NOTE_E5, 4}, {NOTE_E5, 4}, {NOTE_E5, 4}, {NOTE_E5, 4},
  {NOTE_E5, 4}, {NOTE_D5, 4}, {NOTE_D5, 4}, {NOTE_E5, 4},
  {NOTE_D5, 2}, {NOTE_G5, 2}
};


/***************************************
// Buzzer Driver: Play Melody
***************************************/
void PlayMelody() 
{
  static bool output_tone = false;
	static uint8_t current_note = 0;

	// calculate the note duration, take one second divided by the note type
	uint16_t note_duration = 1000/jingleBells[current_note].tempo;
	
	// set a minimum time between notes to distinguish them
	uint8_t pause_duration = note_duration * 1.30;
	uint8_t melody_size = sizeof(jingleBells)/sizeof(jingleBells[0]);
	
	uint64_t current_millis = millis();
	static uint64_t previous_millis = 0;

	if(play_melody == true && output_tone == true)
	{
		// currently playing a tone
		// check if the tone duration has been completed
		if(current_millis - previous_millis >= note_duration)
		{
			previous_millis = current_millis;
			noTone(BUZZER_PIN);
			output_tone = false;

			// update note index && index guard
			current_note++;
			if(current_note >= melody_size)
			{
				// finish the melody if it reaches the end
				current_note = 0;
				play_melody = false;
				noTone(BUZZER_PIN);
			}
		}
	}
	else if(play_melody == true && output_tone == false)
	{
		// currently in a pause
		// check if the pause between notes has been completed
		if(current_millis - previous_millis >= pause_duration)
		{
			previous_millis = current_millis;
			tone(BUZZER_PIN, jingleBells[current_note].notes);
			output_tone = true;
		}
	}
}