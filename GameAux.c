#include "GameAux.h"
#include "VerifyWin.h"
#include "Bot.h"
#include "Special.h"
#include <stdio.h>
#include <string.h>

#define RESET "\033[0m"

void showTable(int c, int r, Position table[r][c]) {
  printf(" 1  2  3  4  5  6  7\n");
  printf(" |  |  |  |  |  |  |\n");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
        Position pos = table[i][j];
        char color[50] = "\033[0m";

        if (pos.pieceType == 1) strcpy(color, "\033[0;34m");
        else if (pos.pieceType == 2) strcpy(color, "\033[0;31m");
        if (pos.winPiece){

          strcpy(color, "\033[0;32m");
        }
      printf("%s %c "RESET, color, pos.symbol);
    }
    printf("\n");
  }
  printf("\n");
}

int addPiece(int c, int r, Position table[r][c], int chosenCol, Player player, int pieceType) {
  // caso não tenha como colocar peça
  if (table[0][chosenCol].symbol != '.') {
    printf("posição invalida, essa coluna está completa\n");
    return -1;
  }

  // Lógica de queda da peça
  for (int i = 0; i < r; i++) {
    int reachEndOfTable = table[i + 1][chosenCol].symbol != '.' || i + 1 >= r;

    // Adição da peça
    if (reachEndOfTable) {
      table[i][chosenCol].symbol = player.symbol;
      table[i][chosenCol].pieceType = pieceType;

      // Se a peça debaixo for uma mina, explodir-lá
      if (i + 1 < c && table[i + 1][chosenCol].pieceType == 2)
        applyExplosion(c, r, table, i + 1, chosenCol);

      return i; // retorna a linha onde foi adicionada a peça
    }
  }

  return -1;
}

void fillTable(int colNum, int rowNum, Position table[rowNum][colNum]) {
  for (int i = 0; i < rowNum; i++) {
    for (int j = 0; j < colNum; j++) {
        emptyPosition(colNum, rowNum, table, i, j);
    }
  }
}

void emptyPosition(int colNum, int rowNum, Position table[rowNum][colNum], int i, int j) {
    table[i][j].symbol = '.';
    table[i][j].pieceType = -1;
    table[i][j].winPiece = 0;
}

void coloringWinPieces(int colNum, int rowNum, Position table[rowNum][colNum], int winPiecesCount, SymbolCoordinates piecesCoord[7]) {
  for (int i = 0; i < winPiecesCount; i++) {
    int rowCoord = piecesCoord[i].x;
    int colCoord = piecesCoord[i].y;

    table[rowCoord][colCoord].winPiece = 1;
  }
}
