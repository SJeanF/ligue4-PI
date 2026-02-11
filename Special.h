#include "GameStructs.h"

#ifndef SPECIAL_H
#define SPECIAL_H

void applyGravity(int colNum, int rowNum, Position table[rowNum][colNum]);

void applyExplosion(int colNum, int rowNum, Position table[rowNum][colNum], int x, int y);

#endif
