#include <stdio.h>
#include "GameStructs.h"
#include "VerifyWin.h"

int horizontalWinVerify(int c, int r, Position table[r][c], int currentRow,
                        char symbol) {
  int cont = 0;

  for (int i = 0; i < c; i++) {
    if (table[currentRow][i].symbol == symbol) {
      cont++;
    } else if (cont < 4) { // Garante consecutividade das peças
      cont = 0;
    }
  }

  if (cont >= 4) {
    printf("alguém ganhou saporra, horizontalmente\n");
    return 1;
  }

  return 0;
}

int verticalWinVerify(int c, int r, Position table[r][c], int currentCol,
                      char symbol) {
  int cont = 0;

  for (int j = 0; j < r; j++) {
    if (table[j][currentCol].symbol == symbol) {
      cont++;
    } else if (cont < 4) {
      cont = 0;
    }
  }

  if (cont >= 4) {
    printf("alguém ganhou saporra, verticalmente\n");
    return 1;
  }

  return 0;
}

int mainDiagonalWinVerify(int c, int r, Position table[r][c], int currentRow,
                          int currentCol, char symbol) {
  int cont = 1; // inicia com um pois a propria posição adicionada já conta como
                // criterio de vitoria
  // verificação sentido NW
  for (int i = currentRow - 1, j = currentCol - 1; i >= 0 && j >= 0; i--, j--) {

    if (table[i][j].symbol == symbol) {
      cont++;
    } else {
      break;
    }
  }

  // verificação sentido SE
  for (int i = currentRow + 1, j = currentCol + 1; i < r && j < c; i++, j++) {

    if (table[i][j].symbol == '#') {
      cont++;
    } else {
      break;
    }
  }

  if (cont >= 4) {
    printf("alguém ganhou alguma coisa  na diagonal principal\n");
    return 1;
  }

  return 0;
}

int antiDiagonalWinVerify(int c, int r, Position table[r][c], int currentRow,
                          int currentCol, char symbol) {
  int cont = 1; // inicia com um pois a propria posição adicionada já conta como
                // criterio de vitoria

  // verificação sentido NE
  for (int i = currentRow - 1, j = currentCol + 1; i >= 0 && j < c; i--, j++) {

    if (table[i][j].symbol == symbol) {
      cont++;
    } else {
      break;
    }
  }

  // verificação sentido SW
  for (int i = currentRow + 1, j = currentCol - 1; i < r && j >= 0; i++, j--) {

    if (table[i][j].symbol == '#') {
      cont++;
    } else {
      break;
    }
  }

  if (cont >= 4) {
    printf("alguém ganhou algo na diagonal secundaria\n");
    return 1;
  }

  return 0;
}
