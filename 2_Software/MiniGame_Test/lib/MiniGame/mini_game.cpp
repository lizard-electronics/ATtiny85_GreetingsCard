#include <mini_game.h>

// Inicialização das variáveis estáticas
const byte MiniGame::obstacleBitmap[8] = { 0b11111111 };
const int MiniGame::FRAME_DELAY = 250;
const unsigned int MiniGame::minFrameDelay = 50;
const unsigned int MiniGame::frameDecrement = 5;

MiniGame::MiniGame()
    : playerY(GROUND_Y - PLAYER_SIZE), playerVelocity(0), isJumping(false),
      score(0), obstacleX(SCREEN_WIDTH), lastFrameTime(0), gameState(START) {}

void MiniGame::loop() {
    unsigned long currentTime = millis();
    static unsigned long currentFrameDelay = 200;

    switch (gameState) {
    case START:
        OzOled.printString("Press START", 1, 1);
        if (digitalRead(1) == HIGH) {
            gameState = PLAYING;
            OzOled.clearDisplay();
            currentFrameDelay = 200;
        }
        break;

    case PLAYING:
        if (currentTime - lastFrameTime < currentFrameDelay) break;
        lastFrameTime = currentTime;

        obstacleX -= 1;
        if (obstacleX < 0) {
            obstacleX = SCREEN_WIDTH;
            score++;
            if (currentFrameDelay > minFrameDelay) {
                currentFrameDelay -= frameDecrement;
            }
        }

        if (digitalRead(1) == HIGH && !isJumping) {
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
            gameState = GAME_OVER;
            OzOled.clearDisplay();
        }
        break;

    case GAME_OVER:
        OzOled.printString("Game Over", 0, 1);
        OzOled.printString("Score: ", 0, 2);
        OzOled.printString(scoreStr, strlen("Score: "), 2);
        OzOled.printString("Press to Restart", 0, 3);
        if (digitalRead(1) == HIGH) {
            resetGame();
            OzOled.clearDisplay();
        }
        break;
    }
}

void MiniGame::drawGround() {
    for (byte x = 0; x < SCREEN_WIDTH; x++) {
        OzOled.printChar('-', x, GROUND_Y);
    }
}

void MiniGame::drawPlayer() {
    OzOled.printChar('*', PLAYER_X, playerY);
}

void MiniGame::drawObstacle() {
    OzOled.printChar('#', obstacleX, GROUND_Y - OBSTACLE_SIZE);
    OzOled.printChar(' ', obstacleX + OBSTACLE_SIZE, GROUND_Y - OBSTACLE_SIZE);
}

bool MiniGame::checkCollision() {
    return (PLAYER_X == obstacleX && playerY + PLAYER_SIZE > GROUND_Y - OBSTACLE_SIZE);
}

void MiniGame::resetGame() {
    playerY = GROUND_Y - PLAYER_SIZE;
    obstacleX = SCREEN_WIDTH;
    isJumping = false;
    gameState = START;
    score = 0;
}
