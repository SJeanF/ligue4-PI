#include <stdio.h>
#include "GameStructs.h"
#include "GameAux.h"
#include "VerifyWin.h"

char horizontalWinVerify(int c, int r, Position table[r][c], int currentRow) {
  SymbolCont countedSymbol = {table[currentRow][0].symbol, 0, {}};

  for (int i = 0; i < c; i++) {
    char currentSymbol = table[currentRow][i].symbol;
    SymbolCoordinates currentCoordinates = {currentRow, i};

    if (currentSymbol == '.') { // Garante que '.' não seja considerado peça possivel para vitoria
      countedSymbol.cont = 0;
      countedSymbol.symbol = '\0';
      continue;
    }

    if (currentSymbol == countedSymbol.symbol) {
      countedSymbol.coordinates[countedSymbol.cont] = currentCoordinates;
      countedSymbol.cont++;
    } else if (countedSymbol.cont < 4) { // Garante consecutividade das peças
      countedSymbol.symbol = currentSymbol;
      countedSymbol.cont = 1; // inicia com 1 pois já considera o atual que ocasionou a troca
      countedSymbol.coordinates[0] = currentCoordinates;
    }
    if (countedSymbol.cont >= 4) {
      coloringWinPieces(c, r, table, countedSymbol.cont, countedSymbol.coordinates);
      printf("Cordenadas da vitoria:\n");
      for (int k = 0; k < countedSymbol.cont; k ++ ) {                                                   // só pra debug
        printf("(%d, %d)\n", countedSymbol.coordinates[k].x, countedSymbol.coordinates[k].y);
      }
      return countedSymbol.symbol;
    }
  }

  return '\0';
}

char verticalWinVerify(int c, int r, Position table[r][c], int currentCol) {
  SymbolCont countedSymbol = {table[0][currentCol].symbol, 0, {}};

  for (int i = 0; i < r; i++) {
    char currentSymbol = table[i][currentCol].symbol;
    SymbolCoordinates currentCoordinates = {i, currentCol};

    if (currentSymbol == '.') {
      countedSymbol.cont = 0;
      countedSymbol.symbol = '\0';
      continue;
    }

    if (currentSymbol == countedSymbol.symbol) {
      countedSymbol.coordinates[countedSymbol.cont] = currentCoordinates;
      countedSymbol.cont++;
    } else if (countedSymbol.cont < 4) {
      countedSymbol.symbol = currentSymbol;
      countedSymbol.coordinates[0] = currentCoordinates;    
      countedSymbol.cont = 1;
    }
    if (countedSymbol.cont >= 4) {
      coloringWinPieces(c, r, table, countedSymbol.cont, countedSymbol.coordinates);
      printf("Cordenadas da vitoria:\n");
      for (int k = 0; k < countedSymbol.cont; k ++ ) {                                                   // só pra debug
        printf("(%d, %d)\n", countedSymbol.coordinates[k].x, countedSymbol.coordinates[k].y);
      }
      return countedSymbol.symbol;
    }
  }
  return '\0';
}

char mainDiagonalWinVerify(int c, int r, Position table[r][c], int currentRow, int currentCol) {
  SymbolCoordinates firstCoordinate = {currentRow, currentCol}; 
  SymbolCont countedSymbol = {table[currentRow][currentCol].symbol, 1, {firstCoordinate}}; // inicia com um pois a propria posição adicionada já conta como criterio de vitoria

  // verificação sentido NW
  for (int i = currentRow - 1, j = currentCol - 1; i >= 0 && j >= 0; i--, j--) {
    char currentSymbol = table[i][j].symbol;
    SymbolCoordinates currentCoordinates = {i, j};

    if (table[i][j].symbol == countedSymbol.symbol) {
      countedSymbol.coordinates[countedSymbol.cont] = currentCoordinates;
      countedSymbol.cont++;
    } else break;
  }

  // verificação sentido SE
  for (int i = currentRow + 1, j = currentCol + 1; i < r && j < c; i++, j++) {
    char currentSymbol = table[i][j].symbol;
    SymbolCoordinates currentCoordinates = {i, j};

    if (table[i][j].symbol == countedSymbol.symbol) {
      countedSymbol.coordinates[countedSymbol.cont] = currentCoordinates;
      countedSymbol.cont++;
    } else break;
  }

  if (countedSymbol.cont >= 4) {
    coloringWinPieces(c, r, table, countedSymbol.cont, countedSymbol.coordinates);
    printf("Cordenadas da vitoria:\n");
    for (int k = 0; k < countedSymbol.cont; k ++ ) {                                                   // só pra debug
      printf("(%d, %d)\n", countedSymbol.coordinates[k].x, countedSymbol.coordinates[k].y);
    }
    return countedSymbol.symbol;
  }

  return '\0';
}

char antiDiagonalWinVerify(int c, int r, Position table[r][c], int currentRow, int currentCol) {
  SymbolCoordinates firstCoordinate = {currentRow, currentCol};
  SymbolCont countedSymbol = {table[currentRow][currentCol].symbol, 1, {firstCoordinate}}; // inicia com um pois a propria posição adicionada já conta como criterio de vitoria

  // verificação sentido NE
  for (int i = currentRow - 1, j = currentCol + 1; i >= 0 && j < c; i--, j++) {
    SymbolCoordinates currentCoordinates = {i, j};

    if (table[i][j].symbol == countedSymbol.symbol) {
      countedSymbol.coordinates[countedSymbol.cont] = currentCoordinates;
      countedSymbol.cont++;
    } else break;
  }

  // verificação sentido SW
  for (int i = currentRow + 1, j = currentCol - 1; i < r && j >= 0; i++, j--) {
    SymbolCoordinates currentCoordinates = {i, j};

    if (table[i][j].symbol == countedSymbol.symbol) {
      countedSymbol.coordinates[countedSymbol.cont] = currentCoordinates;
      countedSymbol.cont++;
    } else break;
  }

  if (countedSymbol.cont >= 4) {
    coloringWinPieces(c, r, table, countedSymbol.cont, countedSymbol.coordinates);
    printf("Cordenadas da vitoria:\n");
    for (int k = 0; k < countedSymbol.cont; k ++ ) {                                                   // só pra debug
      printf("(%d, %d)\n", countedSymbol.coordinates[k].x, countedSymbol.coordinates[k].y);
    }
    return countedSymbol.symbol;
  }

  return '\0';
}

void globalWinVerify(int c, int r, Position table[r][c]) {

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

  for (int l = 1; l <= 2; l++) {
    for (int i = l, j = 2; i <= 4 && j <= 4; i++, j++) {
      antiDiagonalWinVerify(c, r, table, i, j);
    }
  }
}

char verifyLocalWin(int c, int r, Position table[r][c], int currentRow,
              int currentCol) {
    char result = horizontalWinVerify(c, r, table, currentRow);
    if (result != '\0')
        return result;
    result = verticalWinVerify(c, r, table, currentCol);
    if (result != '\0')
        return result;
    result = mainDiagonalWinVerify(c, r, table, currentRow, currentCol);
    if (result != '\0')
        return result;
    result = antiDiagonalWinVerify(c, r, table, currentRow, currentCol);
    if (result != '\0')
        return result;
    return '\0';
}
