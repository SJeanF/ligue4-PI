#include "GameStructs.h"

#ifndef GAME_H
#define GAME_H

typedef struct {
    Player players[2];
    Position table[6][7];
    int roundCount;
} Game;

void initializeGame(Game* game);

void setPlayer(Game* game, char name[], char symbol, int player);

int playRound(Game* game);

void playGame(Game* game);

#endif
