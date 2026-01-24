#include "GameStructs.h"

#ifndef GAME_H
#define GAME_H

typedef struct {
    Player players[2];
    Position table[6][7];
    int roundCount;
} Game;

void playGame(Game* game);

#endif
