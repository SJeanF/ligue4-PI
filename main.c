#include <stdio.h>

typedef struct {
  char symbol;
} position;

void showTable(int c, int r, position table[r][c]) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf(" %c ", table[i][j].symbol);
    }
    printf("\n");
  }
  printf("\n");
}

void horizontalWinVerify(int c, int r, position table[r][c], int currentRow) {
  int cont = 0;

  for (int i = 0; i < c; i++) {
    if (table[currentRow][i].symbol == '#') {
      cont++;
    } else if (cont < 4) {
      cont = 0;
    }
  }

  if (cont >= 4) {
    printf("alguém ganhou saporra, horizontalmente\n");
  }
}

void verticalWinVerify(int c, int r, position table[r][c], int currentCol) {
  int cont = 0;

  for (int j = 0; j < r; j++) {
    if (table[j][currentCol].symbol == '#') {
      cont++;
    } else if (cont < 4) {
      cont = 0;
    }
  }

  if (cont >= 4) {
    printf("alguém ganhou saporra, verticalmente\n");
  }
}

void mainDiagonalWinVerify(int c, int r, position table[r][c], int currentRow,
                           int currentCol) {
  int cont = 1; // inicia com um pois a propria posição adicionada já conta como
                // criterio de vitoria
  // verificação sentido NW
  for (int i = currentRow - 1, j = currentCol - 1; i >= 0 && j >= 0; i--, j--) {

    if (table[i][j].symbol == '#') {
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
  }
}

void AntiDiagonalWinverify(int c, int r, position table[r][c], int currentRow,
                           int currentCol) {
  int cont = 1; // inicia com um pois a propria posição adicionada já conta como
                // criterio de vitoria

  // verificação sentido NE
  for (int i = currentRow - 1, j = currentCol + 1; i >= 0 && j < c; i--, j++) {

    if (table[i][j].symbol == '#') {
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
    printf("alguém ganhou algo na diagonal secundaria");
  }
}

int addPiece(int c, int r, position table[r][c], int chosenCol, int isPlayer1) {

  char pieceToAdd = isPlayer1 ? '#' : '@';

  // caso não tenha como colocar peça
  if (table[0][chosenCol].symbol != '.') {
    return printf("posição invalida, essa coluna está completa");
  }

  // Lógica de queda da peça
  for (int j = 0; j < r; j++) {
    int reachEndOfTable = table[j + 1][chosenCol].symbol != '.' || j + 1 >= r;

    if (reachEndOfTable) {
      table[j][chosenCol].symbol = pieceToAdd;
      verticalWinVerify(c, r, table, chosenCol);
      horizontalWinVerify(c, r, table, j);
      return 0;
    }
  }

  return 0;
}

int main() {

  int colNum = 7, rowNum = 6;
  position table[rowNum][colNum];

  for (int i = 0; i < rowNum; i++) {

    for (int j = 0; j < colNum; j++) {

      table[i][j].symbol = '.';
    }
  }

  printf("Tabela Inicial\n");
  showTable(colNum, rowNum, table);

  addPiece(colNum, rowNum, table, 0, 1);
  addPiece(colNum, rowNum, table, 1, 1);
  addPiece(colNum, rowNum, table, 2, 1);
  addPiece(colNum, rowNum, table, 3, 1);

  printf("Tabela Depois da jogada 1\n");
  showTable(colNum, rowNum, table);

  return 0;
}

// [[0, 1, 2, 3, 4, 5, 6],
//  [0, 1, 2, 3, 4, 5, 6],
//  [0, 1, 2, 3, 4, 5, 6],
//  [0, 1, 2, 3, 4, 5, 6],
//  [0, 1, 2, 3, 4, 5, 6],
//  [0, 1, 2, 3, 4, 5, 6]]

// [
//   [
//     0,
//     1,
//     2,
//     3,
//     4,
//     5,
//     6
//   ],
// ]
