#include <stdio.h>

typedef struct {

  char symbol;



} position;


void showTable(int c,int l, position table[l][c]) {

  
  for (int i = 0; i < l; i++) {
    

    for (int j = 0; j < c; j++) {

      printf(" %c ", table[i][j].symbol);
    }

    printf("\n");
  }
  printf("\n");
}

void winVerify(int c, int l, position table[l][c], int currentPieceCoodinates[2]) {


}

void addPiece(int c, int l, position table[l][c], int chosenCol, int isPlayer1) {
  
  char pieceToAdd = isPlayer1? '#': '@';

  for (int j = 0; j < l; j++) {

    if (table[j + 1][chosenCol].symbol != '.' ||   j + 1 > l - 1) {


      table[j][chosenCol].symbol = pieceToAdd;
      int finalPieceCoordinates[2] = {chosenCol, j};

      winVerify(c, l, table, finalPieceCoordinates);
      return;
    }
  }
}



int main() {

  int colNum = 7, lineNum = 6;
  position table[lineNum][colNum];

  for (int i = 0; i < lineNum; i++) {

    for (int j = 0; j < colNum; j++) {

      table[i][j].symbol = '.';
    }
  }

  printf("Tabela Inicial\n");
  showTable(colNum, lineNum, table);
  addPiece(colNum, lineNum, table, 3, 1);
  addPiece(colNum, lineNum, table, 3, 0);
  addPiece(colNum, lineNum, table, 3, 0);
  addPiece(colNum, lineNum, table, 0, 1);
  addPiece(colNum, lineNum, table, 1, 1);
  addPiece(colNum, lineNum, table, 2, 1);
  addPiece(colNum, lineNum, table, 2, 0);
  addPiece(colNum, lineNum, table, 1, 1);
  addPiece(colNum, lineNum, table, 2, 1);
  addPiece(colNum, lineNum, table, 3, 1);

  printf("Tabela Final\n");
  showTable(colNum, lineNum, table);

  return 0;
}


// [[0, 1, 2, 3, 4, 5, 6], 
//  [0, 1, 2, 3, 4, 5, 6], 
//  [0, 1, 2, 3, 4, 5, 6], 
//  [0, 1, 2, 3, 4, 5, 6], 
//  [0, 1, 2, 3, 4, 5, 6], 
//  [0, 1, 2, 3, 4, 5, 6]]
