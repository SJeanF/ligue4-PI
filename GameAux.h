#include "Game.h"
#include "GameStructs.h"

#ifndef GAMEAUX_H
#define GAMEAUX_H

typedef struct {
  int pieceType, chosenCol;
} BotChoice;

void showTable(int c, int r, Position table[r][c]);

int addPiece(int c, int r, Position table[r][c], int chosenCol, Player player, int pieceType);

void fillTable(int colNum, int rowNum, Position table[rowNum][colNum]);

void botPlayMessage(char* botName, int pieceType, int col);

void coloringWinPieces(int colNum, int rowNum, Position table[rowNum][colNum], int winPiecesCount, SymbolCoordinates piecesCoord[7]);

BotChoice botPlay(Game *game, int botId);

#endif
