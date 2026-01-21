#include "Game.h"
#include "VerifyWin.h"
#include "GameAux.h"
#include <stdio.h>
#include <string.h>

int main() {
  Game game;
  initializeGame(&game);
  setPlayer(&game, "Douglas", '@', 1);
  setPlayer(&game, "Luiz", '#', 2);
  playGame(&game);

  return 0;
}
