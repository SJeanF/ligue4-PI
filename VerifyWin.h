#include "GameStructs.h"

#ifndef VERIFYWIN_H
#define VERIFYWIN_H

int horizontalWinVerify(int c, int r, Position table[r][c], int currentRow,
                        char symbol);

int verticalWinVerify(int c, int r, Position table[r][c], int currentCol,
                      char symbol);

int mainDiagonalWinVerify(int c, int r, Position table[r][c], int currentRow,
                          int currentCol, char symbol);

int antiDiagonalWinVerify(int c, int r, Position table[r][c], int currentRow,
                          int currentCol, char symbol);

#endif
