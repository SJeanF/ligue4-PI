#include "Game.h"
#include "GameStructs.h"


int portalActive(int c, int r, Position table[r][c], Player player, int chosenCol, int chosenRow) {
  table[chosenRow][chosenCol].symbol = player.symbol;
  table[chosenRow][chosenCol].pieceType = 1;
  return chosenRow;
}
