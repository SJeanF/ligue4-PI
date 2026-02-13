#include "GameStructs.h"

#ifndef VERIFYWIN_H
#define VERIFYWIN_H

char horizontalWinVerify(int c, int r, Position table[r][c], int currentRow);

char verticalWinVerify(int c, int r, Position table[r][c], int currentCol);

char mainDiagonalWinVerify(int c, int r, Position table[r][c], int currentRow, int currentCol);

char antiDiagonalWinVerify(int c, int r, Position table[r][c], int currentRow, int currentCol);

char globalWinVerify(int c, int r, Position table[r][c], Player playerRequest, Player players[2]);

char verifyLocalWin(int c, int r, Position table[r][c], int currentRow, int currentCol);

#endif
