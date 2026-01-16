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
  if (horizontalWinVerify(c, r, table, currentRow, symbol))
    return;
  if (verticalWinVerify(c, r, table, currentCol, symbol))
    return;
  if (mainDiagonalWinVerify(c, r, table, currentRow, currentCol, symbol))
    return;
  if (antiDiagonalWinVerify(c, r, table, currentRow, currentCol, symbol))
    return;
  return;
}

int addPiece(int c, int r, Position table[r][c], int chosenCol, Player player) {
  // caso não tenha como colocar peça
  if (table[0][chosenCol].symbol != '.') {
    return printf("posição invalida, essa coluna está completa");
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
      verifyWin(c, r, table, i, chosenCol, *player.symbol);

      return 0;
    }
  }

  return 0;
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

  addPiece(colNum, rowNum, table, 3, player1);
  addPiece(colNum, rowNum, table, 3, player1);
  addPiece(colNum, rowNum, table, 3, player1);
  addPiece(colNum, rowNum, table, 3, player1);
  // addPiece(colNum, rowNum, table, 3, player2);

  return 0;
}
