#include "Special.h"
#include "GameAux.h"
#include "GameStructs.h"
#include <stdio.h>

void applyGravity(int colNum, int rowNum, Position table[rowNum][colNum]) {
  for (int x = 0; x < rowNum; x++) {
    for (int y = 0; y < colNum; y++) {

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
    }
  }
}
