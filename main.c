#include "GameStructs.h"
#include "Game.h"
#include "VerifyWin.h"
#include "GameAux.h"
#include <stdio.h>
#include <string.h>

int main() {
  // int colNum = 7, rowNum = 6;
  // Position table[rowNum][colNum];
  // fillTable(colNum, rowNum, table);

  // Player player1;
  // strcpy(player1.name, "Jean");
  // player1.symbol = "@";

  // Player player2;
  // strcpy(player2.name, "Luiz");
  // player2.symbol = "#";

  // printf("Tabela Inicial\n");
  // showTable(colNum, rowNum, table);

  // completeBoard(colNum, rowNum, table, player1, player2);

  // printf("tabela final\n");
  // showTable(colNum, rowNum, table);

  Game game;
  initializeGame(&game);
  setPlayer(&game, "Douglas", '@', 1);
  setPlayer(&game, "Luiz", '#', 2);
  playGame(&game);

  return 0;
}
