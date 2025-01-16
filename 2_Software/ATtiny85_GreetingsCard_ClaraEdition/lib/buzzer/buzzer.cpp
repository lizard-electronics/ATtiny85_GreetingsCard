#include <buzzer.h>

// Frequências das notas musicais (em Hz)
const int NOTE_C4 = 262; // C4
const int NOTE_E4 = 330; // E4
const int NOTE_G4 = 392; // G4
const int NOTE_A4 = 440; // A4
const int NOTE_E5 = 659; // E5

// Função para tocar uma nota
void playTone(int frequency, int duration) {
    tone(BUZZER_PIN, frequency, duration);
    delay(duration);
    noTone(BUZZER_PIN);
}

// Efeito sonoro de inicialização
void playStartupSound() {
    playTone(NOTE_C4, 250);
    playTone(NOTE_E4, 250);
    playTone(NOTE_A4, 250);
}

// Efeito sonoro de feedback ao pressionar o botão
void playButtonFeedback() {
    playTone(NOTE_A4, 150);
}

void playGameOver() {
    playTone(NOTE_G4, 150);
    playTone(NOTE_C4, 500);
}

void playVictory() {
    playTone(NOTE_A4, 150);
    playTone(NOTE_E5, 500);
}
