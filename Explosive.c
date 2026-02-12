#include "Explosive.h"
#include "GameAux.h"
#include "GameStructs.h"
#include <stdio.h>

void applyGravity(int colNum, int rowNum, Position table[rowNum][colNum]) {
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
