#ifndef _MINIGAME_H
#define _MINIGAME_H

#include <TinyOzOled.h>
#include <system_hardware.h>
#include <buzzer.h>
#include <styles.h>

// Constantes do jogo
#define SCREEN_WIDTH 16
#define SCREEN_HEIGHT 4
#define GROUND_Y 3
#define PLAYER_X 2
#define PLAYER_SIZE 1
#define OBSTACLE_SIZE 1

// Declarações das funções
void loopMiniGame();
void printStartScreen();

#endif