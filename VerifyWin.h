#include "GameStructs.h"

#ifndef VERIFYWIN_H
#define VERIFYWIN_H

int horizontalWinVerify(int c, int r, Position table[r][c], int currentRow);

int verticalWinVerify(int c, int r, Position table[r][c], int currentCol);

int mainDiagonalWinVerify(int c, int r, Position table[r][c], int currentRow,
                          int currentCol);

int antiDiagonalWinVerify(int c, int r, Position table[r][c], int currentRow,
                          int currentCol);

#endif
