#include <TinyOzOled.h>
#include <mini_game.h>

MiniGame miniGame;

// Setup inicial
void setup() {
  OzOled.init();             // Inicializa o display
  OzOled.sendCommand(0xA8);  // Multiplexer
  OzOled.sendCommand(0x1F);  // 32 linhas
  OzOled.sendCommand(0xDA);  // COM pins
  OzOled.sendCommand(0x02);  // Pins
  OzOled.clearDisplay();     
  OzOled.setNormalDisplay();
  OzOled.sendCommand(0xA1);
  OzOled.sendCommand(0xC8);
  OzOled.setHorizontalMode();
  OzOled.setBrightness(255);

  pinMode(1, INPUT);  // Configura o botão com pull-down no pino 1
}

// Loop principal
void loop() {
  miniGame.loop();
}
