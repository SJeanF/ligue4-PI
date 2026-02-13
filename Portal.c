#include "Game.h"
#include "GameStructs.h"
#include "GameAux.h"

int portalActive(int c, int r, Position table[r][c], Player player, int chosenCol, int chosenRow) {
  table[chosenRow][chosenCol].symbol = player.symbol;
  table[chosenRow][chosenCol].pieceType = 1;
  return chosenRow;
}

void removeLast(int c, int r, Position table[r][c], int chosenCol) {
  for (int i = 0; i < r; i++) {
    int nextRow = i + 1;
    int nextRowAvailable = table[nextRow][chosenCol].symbol == '.';

    if (!nextRowAvailable) {
      emptyPosition(c, r, table, nextRow, chosenCol);
      return;
    }
  }
}
