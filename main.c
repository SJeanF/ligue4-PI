#include <stdio.h>
#include <string.h>
#include "GameStructs.h"
#include "VerifyWin.h"

void showTable(int c, int r, Position table[r][c]) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf(" %c ", table[i][j].symbol);
    }
    printf("\n");
  }
  printf("\n");
}

void verifyWin(int c, int r, Position table[r][c], int currentRow,
              int currentCol, char symbol) {
  // if (horizontalWinVerify(c, r, table, currentRow, symbol))
  //   return;
  // if (verticalWinVerify(c, r, table, currentCol, symbol))
  //   return;
  // if (mainDiagonalWinVerify(c, r, table, currentRow, currentCol, symbol))
  //   return;
  // if (antiDiagonalWinVerify(c, r, table, currentRow, currentCol, symbol))
  //   return;
  // return;
}

void globalWinVerify (int c, int r, Position table[r][c]) {
  
  for (int i = 0; i < r; i++) {
    horizontalWinVerify(c, r, table, i);
  }

  for (int j = 0; j < c; j++) {
    verticalWinVerify(c, r, table, j);
  }

  for (int l = 3; l <= 4; l++) {
    for (int i = l, j = 2; i >= 1 && j <= 4; i--, j++) {
      mainDiagonalWinVerify(c, r, table, i, j);
    }
  }

  for (int l = 1; l <= 2; l++){
    for (int i = l, j = 2; i <= 4 && j <= 4; i++, j++) {
      antiDiagonalWinVerify(c, r, table, i, j);
    }
  }
  

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
      table[i][chosenCol].symbol = *player.symbol;

      printf("Jogador %s\n", player.name);
      showTable(c, r, table);

      // Verificação de vitória
      // verifyWin(c, r, table, i, chosenCol, *player.symbol);                        //  tá comentada a verificação local

      return 0;
    }
  }

  return 0;
}

int completeBoard(int colNum, int rowNum, Position table[rowNum][colNum], Player player1, Player player2) {
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

int main() {

  int colNum = 7, rowNum = 6;
  Position table[rowNum][colNum];

  Player player1;
  strcpy(player1.name, "Jean");
  player1.symbol = "@";

  Player player2;
  strcpy(player2.name, "Luiz");
  player2.symbol = "#";

  for (int i = 0; i < rowNum; i++) {
    for (int j = 0; j < colNum; j++) {
      table[i][j].symbol = '.';
    }
  }

  printf("Tabela Inicial\n");
  showTable(colNum, rowNum, table);

  completeBoard(colNum, rowNum, table, player1, player2);

  printf("tabela final\n");
  showTable(colNum, rowNum, table);


  globalWinVerify(colNum, rowNum, table);

  // addPiece(colNum, rowNum, table, 0, player1);
  // addPiece(colNum, rowNum, table, 1, player2);
  // addPiece(colNum, rowNum, table, 2, player2);
  // addPiece(colNum, rowNum, table, 3, player1);
  // addPiece(colNum, rowNum, table, 4, player1);
  // addPiece(colNum, rowNum, table, 5, player1);
  // addPiece(colNum, rowNum, table, 6, player1);

  return 0;
}
