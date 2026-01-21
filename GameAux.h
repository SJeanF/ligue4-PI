#include "GameStructs.h"

#ifndef GAMEAUX_H
#define GAMEAUX_H

void showTable(int c, int r, Position table[r][c]);

int addPiece(int c, int r, Position table[r][c], int chosenCol, Player player);

void fillTable(int colNum, int rowNum, Position table[rowNum][colNum]);

int completeBoard(int colNum, int rowNum, Position table[rowNum][colNum],
                  Player player1, Player player2);

#endif
