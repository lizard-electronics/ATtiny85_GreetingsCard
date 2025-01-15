#include <mini_game.h>

// Variáveis globais
static uint8_t gameState = 0;
uint8_t playerY = GROUND_Y - PLAYER_SIZE;
uint8_t playerVelocity = 0;
bool isJumping = false;
uint8_t score = 0;
char scoreStr[10];
int8_t obstacleX = SCREEN_WIDTH;

unsigned long lastFrameTime = 0;
const uint8_t FRAME_DELAY = 250;
const uint8_t minFrameDelay = 50;
const uint8_t frameDecrement = 5;

// Funções internas (não expostas no cabeçalho)
void drawGround();
void drawPlayer();
void drawObstacle();
bool checkCollision();
void resetGame();

// Função principal do loop do jogo
void loopMiniGame() {
  unsigned long currentTime = millis();
  static unsigned long currentFrameDelay = 200;

  switch (gameState) {
    case 0:
      if (digitalRead(BUTTON_PIN) == LOW) {
        gameState = 1;
      }
      break;

    case 1: // START
      if (digitalRead(BUTTON_PIN)) {
        gameState = 2;
        playButtonFeedback();
        OzOled.clearDisplay();
      }
      break;

    case 2: // PLAYING
      if (currentTime - lastFrameTime < currentFrameDelay) break;
      lastFrameTime = currentTime;

      obstacleX -= 1;
      if (obstacleX < 0) {
        obstacleX = SCREEN_WIDTH;
        if (currentFrameDelay > minFrameDelay) {
            currentFrameDelay -= frameDecrement;
        }        
        if(score++ >= 254) {
          playVictory();
          resetGame();
          currentFrameDelay = 200;
          break;
        }
      }

      if (digitalRead(BUTTON_PIN) && !isJumping) {
        playButtonFeedback();
        isJumping = true;
        playerVelocity = -1;
      }

      if (isJumping) {
        OzOled.printChar(' ', PLAYER_X, playerY);
        playerY += playerVelocity;
        playerVelocity++;
        if (playerY >= GROUND_Y - PLAYER_SIZE) {
            playerY = GROUND_Y - PLAYER_SIZE;
            isJumping = false;
        }
      }

      drawGround();
      drawPlayer();
      drawObstacle();
      itoa(score, scoreStr, 10);
      OzOled.printString("Score: ", 0, 0);
      OzOled.printString(scoreStr, strlen("Score: "), 0);

      if (checkCollision()) {
        gameState = 3;
        OzOled.clearDisplay();
        OzOled.printString("Game Over", 0, 1);
        OzOled.printString("Score: ", 0, 2);
        OzOled.printString(scoreStr, strlen("Score: "), 2);
        OzOled.printString("Press to Restart", 0, 3);
        playGameOver();
      }
      break;

    case 3: // GAME_OVER
      if (digitalRead(BUTTON_PIN)) {
        resetGame();
        currentFrameDelay = 200;
      }
      break;
    }
}

void drawGround() {
  for (byte x = 0; x < SCREEN_WIDTH; x++) {
    OzOled.printChar('-', x, GROUND_Y);
  }
}

void drawPlayer() {
  OzOled.printChar('*', PLAYER_X, playerY);
}

void drawObstacle() {
  OzOled.printChar('#', obstacleX, GROUND_Y - OBSTACLE_SIZE);
  OzOled.printChar(' ', obstacleX + OBSTACLE_SIZE, GROUND_Y - OBSTACLE_SIZE);
}

bool checkCollision() {
  return (PLAYER_X == obstacleX && playerY + PLAYER_SIZE > GROUND_Y - OBSTACLE_SIZE);
}

void resetGame() {
  playerY = GROUND_Y - PLAYER_SIZE;
  obstacleX = SCREEN_WIDTH;
  isJumping = false;
  score = 0;
  gameState = 1;
  OzOled.clearDisplay();
  OzOled.printString("Press START", 1, 1);
}
