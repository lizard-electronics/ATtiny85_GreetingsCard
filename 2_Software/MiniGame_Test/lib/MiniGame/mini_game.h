#ifndef _MINIGAME_H
#define _MINIGAME_H

#include <TinyOzOled.h>

// Estados do jogo
enum GameState { START, PLAYING, GAME_OVER };

class MiniGame {
public:
    MiniGame();
    void loop();

private:
    // Constantes do jogo
    static const int SCREEN_WIDTH = 16;
    static const int SCREEN_HEIGHT = 4;
    static const int GROUND_Y = 3;
    static const int PLAYER_X = 2;
    static const int PLAYER_SIZE = 1;
    static const int OBSTACLE_SIZE = 1;

    // Variáveis do jogador
    int playerY;
    int playerVelocity;
    bool isJumping;
    int score;
    char scoreStr[10];

    // Variáveis do obstáculo
    int obstacleX;
    static const byte obstacleBitmap[8];

    // Variáveis gerais
    unsigned long lastFrameTime;
    static const int FRAME_DELAY;
    static const unsigned int minFrameDelay;
    static const unsigned int frameDecrement;
    GameState gameState;

    // Funções auxiliares
    void drawGround();
    void drawPlayer();
    void drawObstacle();
    bool checkCollision();
    void resetGame();
};

#endif