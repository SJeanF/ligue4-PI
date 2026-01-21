#include "GameStructs.h"
#include "VerifyWin.h"
#include "GameAux.h"
#include <stdio.h>
#include <string.h>

void showTable(int c, int r, Position table[r][c]) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf(" %c ", table[i][j].symbol);
    }
    printf("\n");
  }
  printf("\n");
}

int addPiece(int c, int r, Position table[r][c], int chosenCol, Player player) {
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
      return i; // retorna a linha onde foi adicionada a peça
    }
  }

  return -1;
}

void fillTable(int colNum, int rowNum, Position table[rowNum][colNum]) {
  for (int i = 0; i < rowNum; i++) {
    for (int j = 0; j < colNum; j++) {
      table[i][j].symbol = '.';
    }
  }
}

int completeBoard(int colNum, int rowNum, Position table[rowNum][colNum],
                  Player player1, Player player2) {
  // Coluna 0
  addPiece(colNum, rowNum, table, 0, player1);
  addPiece(colNum, rowNum, table, 0, player2);
  addPiece(colNum, rowNum, table, 0, player2);
  addPiece(colNum, rowNum, table, 0, player1);
  addPiece(colNum, rowNum, table, 0, player1);
  addPiece(colNum, rowNum, table, 0, player2);

  // Coluna 1
  addPiece(colNum, rowNum, table, 1, player2);
  addPiece(colNum, rowNum, table, 1, player1);
  addPiece(colNum, rowNum, table, 1, player1);
  addPiece(colNum, rowNum, table, 1, player2);
  addPiece(colNum, rowNum, table, 1, player1);
  addPiece(colNum, rowNum, table, 1, player2);

  // Coluna 2
  addPiece(colNum, rowNum, table, 2, player1);
  addPiece(colNum, rowNum, table, 2, player2);
  addPiece(colNum, rowNum, table, 2, player1);
  addPiece(colNum, rowNum, table, 2, player1);
  addPiece(colNum, rowNum, table, 2, player2);
  addPiece(colNum, rowNum, table, 2, player2);

  // Coluna 3
  addPiece(colNum, rowNum, table, 3, player2);
  addPiece(colNum, rowNum, table, 3, player2);
  addPiece(colNum, rowNum, table, 3, player1);
  addPiece(colNum, rowNum, table, 3, player1);
  addPiece(colNum, rowNum, table, 3, player2);
  addPiece(colNum, rowNum, table, 3, player1);

  // Coluna 4
  addPiece(colNum, rowNum, table, 4, player1);
  addPiece(colNum, rowNum, table, 4, player1);
  addPiece(colNum, rowNum, table, 4, player2);
  addPiece(colNum, rowNum, table, 4, player2);
  addPiece(colNum, rowNum, table, 4, player1);
  addPiece(colNum, rowNum, table, 4, player2);

  // Coluna 5
  addPiece(colNum, rowNum, table, 5, player2);
  addPiece(colNum, rowNum, table, 5, player1);
  addPiece(colNum, rowNum, table, 5, player2);
  addPiece(colNum, rowNum, table, 5, player1);
  addPiece(colNum, rowNum, table, 5, player1);
  addPiece(colNum, rowNum, table, 5, player2);

  // Coluna 6
  addPiece(colNum, rowNum, table, 6, player1);
  addPiece(colNum, rowNum, table, 6, player2);
  addPiece(colNum, rowNum, table, 6, player1);
  addPiece(colNum, rowNum, table, 6, player2);
  addPiece(colNum, rowNum, table, 6, player2);
  addPiece(colNum, rowNum, table, 6, player1);
}
