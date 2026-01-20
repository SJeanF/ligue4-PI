#include <stdio.h>
#include "GameStructs.h"
#include "VerifyWin.h"

int horizontalWinVerify(int c, int r, Position table[r][c], int currentRow) {
  SymbolCont countedSymbol = {table[currentRow][0].symbol, 0};

  for (int i = 0; i < c; i++) {
      char currentPosition = table[currentRow][i].symbol;

    if (currentPosition == '.') { // Garante que '.' não seja considerado peça possivel para vitoria
      continue;
    }

    if (currentPosition == countedSymbol.symbol) {
      countedSymbol.cont++;
      // printf("foram encontrados %d, %c\n", countedSymbol.cont, countedSymbol.symbol);
    } else if (countedSymbol.cont < 4) { // Garante consecutividade das peças
      countedSymbol.symbol = currentPosition;
      // printf("foi encontrado uma quebra na consecutividade, agora o simbolo considerado é '%c'\n", countedSymbol.symbol);
      countedSymbol.cont = 1; // inicia com 1 pois já considera o atual que ocasionou a troca
    }
  }

  if (countedSymbol.cont >= 4) {
    printf("o simbolo '%c' ganhou saporra, horizontalmente\n", countedSymbol.symbol);
    return 1;
  }

  return 0;
}

int verticalWinVerify(int c, int r, Position table[r][c], int currentCol) {
  SymbolCont countedSymbol = {table[0][currentCol].symbol, 0};

  for (int j = 0; j < r; j++) {
    char currentPosition = table[j][currentCol].symbol;
    if (currentPosition == '.') {
      continue;
    }
    if (table[j][currentCol].symbol == countedSymbol.symbol) {
      countedSymbol.cont++;
    } else if (countedSymbol.cont < 4) {
      countedSymbol.symbol = currentPosition;
      countedSymbol.cont = 1;
    }
  }

  if (countedSymbol.cont >= 4) {
    printf("o simbolo '%c' ganhou saporra, verticalmente\n", countedSymbol.symbol);
    return 1;
  }

  return 0;
}

int mainDiagonalWinVerify(int c, int r, Position table[r][c], int currentRow,
                          int currentCol) {
  SymbolCont countedSymbol = {table[currentRow][currentCol].symbol, 1}; // inicia com um pois a propria posição adicionada já conta como
                // criterio de vitoria
  // verificação sentido NW
  for (int i = currentRow - 1, j = currentCol - 1; i >= 0 && j >= 0; i--, j--) {

    if (table[i][j].symbol == countedSymbol.symbol) {
      countedSymbol.cont++;
    } else {
      break;
    }
  }

  // verificação sentido SE
  for (int i = currentRow + 1, j = currentCol + 1; i < r && j < c; i++, j++) {

    if (table[i][j].symbol == countedSymbol.symbol) {
      countedSymbol.cont++;
    } else {
      break;
    }
  }

  if (countedSymbol.cont >= 4) {
    printf("alguém ganhou alguma coisa na diagonal principal\n");
    return 1;
  }

  return 0;
}

int antiDiagonalWinVerify(int c, int r, Position table[r][c], int currentRow,
                          int currentCol) {
  SymbolCont countedSymbol = {table[currentRow][currentCol].symbol, 1}; // inicia com um pois a propria posição adicionada já conta como
                // criterio de vitoria

  // verificação sentido NE
  for (int i = currentRow - 1, j = currentCol + 1; i >= 0 && j < c; i--, j++) {

    if (table[i][j].symbol == countedSymbol.symbol) {
      countedSymbol.cont++;
    } else {
      break;
    }
  }

  // verificação sentido SW
  for (int i = currentRow + 1, j = currentCol - 1; i < r && j >= 0; i++, j--) {

    if (table[i][j].symbol == countedSymbol.symbol) {
      countedSymbol.cont++;
    } else {
      break;
    }
  }

  if (countedSymbol.cont >= 4) {
    printf("alguém ganhou algo na diagonal secundaria\n");
    return 1;
  }

  return 0;
}
