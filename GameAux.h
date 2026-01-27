#include "GameStructs.h"

#ifndef GAMEAUX_H
#define GAMEAUX_H

void showTable(int c, int r, Position table[r][c]);

int addPiece(int c, int r, Position table[r][c], int chosenCol, Player player, int pieceType);

void fillTable(int colNum, int rowNum, Position table[rowNum][colNum]);

void botPlayMessage(char* botName, int pieceType, int col);

void coloringWinPieces(int colNum, int rowNum, Position table[rowNum][colNum], int winPiecesCount, int piecesCoord[7][2]) ;

#endif
