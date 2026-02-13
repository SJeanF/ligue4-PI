#include "Explosive.h"
#include "GameAux.h"
#include "GameStructs.h"
#include "VerifyWin.h"
#include <stdio.h>

void applyGravity(int colNum, int rowNum, Position table[rowNum][colNum]) {   // preparar para essa função possivelmente retornar o simbolo do vencedor
  for (int j = 0; j < colNum; j++) {
      int writeIndex = rowNum - 1;

      for (int i = rowNum - 1; i >= 0; i--) {
          if (table[i][j].pieceType != -1) {
              if (i != writeIndex) {
                  table[writeIndex][j] = table[i][j];
                  emptyPosition(colNum, rowNum, table, i, j);
              }

              writeIndex--;
          }
      }
  }
}

void applyExplosion(int colNum, int rowNum, Position table[rowNum][colNum],
                    int x, int y) {
  for (int i = x - 1; i <= x + 1; i++) {
    if (i < 0 || i >= rowNum)
      continue;

    for (int j = y - 1; j <= y + 1; j++) {
      if (j < 0 || j >= colNum)
        continue;

      emptyPosition(colNum, rowNum, table, i, j);
      applyGravity(colNum, rowNum, table);  
    }
  }
}

int lastPieceIsMine(int colNum, int rowNum, Position table[rowNum][colNum], int chosenCol) {
  for (int i = 0; i < rowNum; i++) {
    int nextRow = i + 1;
    int nextRowAvailable = table[nextRow][chosenCol].symbol == '.';
    int reachEndOfTable = nextRow >= rowNum;

    // Adição da peça
    if (!nextRowAvailable && table[nextRow][chosenCol].pieceType == 2) {
      return 1;
    }
  }
  return 0;
}
