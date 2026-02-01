#include "Game.h"
#include "VerifyWin.h"
#include "GameAux.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  Game game;
  srand(time(NULL));
  playGame(&game);
  return 0;
}
