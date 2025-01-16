#include <Arduino.h>
#include <system_hardware.h>
#include <TinyOzOLED.h>
#include <snowfall.h>
#include <mini_game.h>
#include <buzzer.h>

// Greetings Card states
static uint8_t state = 1;

c_snowfall snowfall;


/***************************************
// Aux Functions
***************************************/
void Draw(c_snowflake *pSnowflake)
{
	uint8_t x = pSnowflake->getPos()->getX();
	uint8_t y = pSnowflake->getPos()->getY();
	// uint8_t bmp_size = pSnowflake->getSize();
  OzOled.drawBitmap(pSnowflake->getImage(), x, y, 1, 1);
}

void Draw(c_snowfall *pSnowfall)
{
	for(uint8_t i=0; i<NUM_FLAKES; i++)
	{
		Draw(&(pSnowfall->snowflakes[i]));
	}
}

void snowfallAnimation()
{
  static bool first_init = true;
  uint64_t current_millis = millis();
	static uint64_t previous_millis = 0;

  if(first_init)
  {
    previous_millis = current_millis;
    first_init = false;
    
    OzOled.clearDisplay();
    Draw(&snowfall);
  }
  else if(!first_init && current_millis - previous_millis >= 1000)
  {
    previous_millis = current_millis;
    
    OzOled.clearDisplay();
    snowfall.Update();
    Draw(&snowfall);
  }
}


/***************************************
// Main Functions
***************************************/
void setup()
{
  pinMode(BUTTON_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  OzOled.init();
  
	OzOled.sendCommand(0xA8); //set multiplexer
	OzOled.sendCommand(0x1F); //32 lines
	OzOled.sendCommand(0xDA); //set COM pins
	OzOled.sendCommand(0x02); //pins

  OzOled.clearDisplay(); 
  OzOled.setNormalDisplay();
  OzOled.sendCommand(0xA1);
  OzOled.sendCommand(0xC8);
  OzOled.setHorizontalMode(); 
  OzOled.setBrightness(255);

  if(digitalRead(BUTTON_PIN))
  {
    state = 0;
    printStartScreen();
  }
  else
  {
    state = 1;
    OzOled.clearDisplay();
    OzOled.drawBitmap(bmp_message0_128x32, 0, 0, 16, 4);
  }

  playStartupSound();
}

void loop()
{
  if(state == 0)
  {
    loopMiniGame();
  }
  else if(state == 1)
  {
    delay(2000);
    state = 2;
    OzOled.clearDisplay();
    OzOled.drawBitmap(bmp_message1_128x32, 0, 0, 16, 4);
  }
  else if(state == 2)
  {
    if(readButton(BUTTON_PIN))
    {
      state = 3;
      playButtonFeedback();

      OzOled.clearDisplay();
      OzOled.drawBitmap(bmp_message2_128x32, 0, 0, 16, 4);
    }
  }
  else if(state == 3)
  {
    if(readButton(BUTTON_PIN))
    {
      state = 4;
      playButtonFeedback();

      OzOled.clearDisplay();
      OzOled.drawBitmap(bmp_message3_128x32, 0, 0, 16, 4);
    }
  }
  else if(state == 4)
  {
    const uint64_t PRESS_DELAY = 2000;
    const uint8_t BAR_START = 3;
    const uint8_t BAR_DISTANCE = 128-BAR_START*8-BAR_START*8;
    static bool button_pressed = false;
    static uint64_t button_since_pressed = 0;
    uint64_t current_millis = millis();

    if(digitalRead(BUTTON_PIN)) // Se o botão está pressionado
    {
      if(!button_pressed) // Se o botão acabou de ser pressionado
      {
        playButtonFeedback();
        button_pressed = true;
        button_since_pressed = current_millis; // Regista o tempo inicial
      }
      
      // Calcula o tempo que o botão está pressionado
      uint64_t press_progress = current_millis - button_since_pressed;

      // Atualiza a barra de progresso na página 3
      uint8_t progress_bar = map(press_progress, 0, PRESS_DELAY, 0, BAR_DISTANCE); // Escala para 128 pixels de largura
      OzOled.setCursorXY(BAR_START,3);
      OzOled.sendCommand(0xB3); // Página 3
      for(uint8_t i = 0; i < progress_bar; i++) {
        OzOled.sendData(0xCF); // Desenha pixels preenchidos
      }

      if(press_progress >= PRESS_DELAY) // Se o botão foi pressionado por 3 segundos
      {
        state = 5; // Avança para o próximo estado
        button_pressed = false; // Reinicia estado do botão
        playVictory();
        OzOled.clearDisplay(); // Limpa o display para o próximo estado
      }
    }
    else if(button_pressed) // Se o botão foi solto
    {
      button_pressed = false; // Reinicia estado do botão
      OzOled.setCursorXY(BAR_START, 3); 
      for(uint8_t i = 0; i < BAR_DISTANCE; i++) {
        OzOled.sendData(0xC0); // Limpa a barra de progresso
      }
    }
  }
  else if(state == 5)
  {
    snowfallAnimation();
  }
}