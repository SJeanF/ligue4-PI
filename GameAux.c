#include "GameStructs.h"
#include "VerifyWin.h"
#include "GameAux.h"
#include <stdio.h>
#include <string.h>

#define RESET "\033[0m"

void showTable(int c, int r, Position table[r][c]) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
        Position pos = table[i][j];
        char color[50] = "\033[0m";

        if (pos.pieceType == 1) strcpy(color, "\033[0;34m");
        else if (pos.pieceType == 2) strcpy(color, "\033[0;31m");

      printf("%s %c "RESET, color, pos.symbol);
    }
    printf("\n");
  }
  printf("\n");
}

int addPiece(int c, int r, Position table[r][c], int chosenCol, Player player, int pieceType) {
  // caso não tenha como colocar peça
  if (table[0][chosenCol].symbol != '.') {
    return printf("posição invalida, essa coluna está completa\n");
  }

  // Lógica de queda da peça
  for (int i = 0; i < r; i++) {
    int reachEndOfTable = table[i + 1][chosenCol].symbol != '.' || i + 1 >= r;

    // Adição da peça
    if (reachEndOfTable) {
      table[i][chosenCol].symbol = player.symbol;
      table[i][chosenCol].pieceType = pieceType;
      return i; // retorna a linha onde foi adicionada a peça
    }
  }

  return -1;
}

void fillTable(int colNum, int rowNum, Position table[rowNum][colNum]) {
  for (int i = 0; i < rowNum; i++) {
    for (int j = 0; j < colNum; j++) {
      table[i][j].symbol = '.';
      table[i][j].pieceType = -1;
    }
  }
}

void botPlayMessage(char* botName, int pieceType, int col) {
  printf("%s jogou uma ficha ", botName);
  switch (pieceType) {
  case 0:
    printf("basica ");
    break;
  case 1:
    printf("portal ");
    break;
  case 2:
    printf("explosiva ");
    break;
  default:
    break;
  }
  printf("na coluna %d\n", col + 1);
}

