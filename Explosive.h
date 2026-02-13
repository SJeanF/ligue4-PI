#include "GameStructs.h"

#ifndef EXPLOSIVE_H
#define EXPLOSIVE_H

void applyGravity(int colNum, int rowNum, Position table[rowNum][colNum]);

void applyExplosion(int colNum, int rowNum, Position table[rowNum][colNum], int x, int y);

int lastPieceIsMine(int colNum, int rowNum, Position table[rowNum][colNum], int chosenCol);

#endif
