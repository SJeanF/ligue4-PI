#include <stdio.h>
#include "Game.h"

#ifndef BOT_H
#define BOT_H

typedef struct {
  int pieceType, chosenCol;
} BotChoice;

BotChoice botPlay(Game *game, int botId);

void botPlayMessage(char* botName, int pieceType, int col);

#endif
