#include "Game.h"
#include "GameStructs.h"
#include "VerifyWin.h"
#include "GameAux.h"
#include <stdio.h>
#include <string.h>

#define RESET "\033[0m"

void showTable(int c, int r, Position table[r][c]) {
  printf(" 1  2  3  4  5  6  7\n");
  printf(" |  |  |  |  |  |  |\n");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
        Position pos = table[i][j];
        char color[50] = "\033[0m";

        if (pos.pieceType == 1) strcpy(color, "\033[0;34m");
        else if (pos.pieceType == 2) strcpy(color, "\033[0;31m");
        if (pos.winPiece){

          strcpy(color, "\033[0;32m");
        } 
      printf("%s %c "RESET, color, pos.symbol);
    }
    printf("\n");
  }
  printf("\n");
}

int addPiece(int c, int r, Position table[r][c], int chosenCol, Player player, int pieceType) {
  // caso não tenha como colocar peça
  if (table[0][chosenCol].symbol != '.') {
    printf("posição invalida, essa coluna está completa\n");
    return -1;
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
      table[i][j].winPiece = 0;
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
  printf("na coluna %d\n\n", col + 1);
}

void coloringWinPieces(int colNum, int rowNum, Position table[rowNum][colNum], int winPiecesCount, SymbolCoordinates piecesCoord[7]) {
  for (int i = 0; i < winPiecesCount; i++) {
    int rowCoord = piecesCoord[i].x;
    int colCoord = piecesCoord[i].y;

    table[rowCoord][colCoord].winPiece = 1;
  }
}

BotChoice botPlay(Game *game, int botId) {
  // Escolha do tipo da ficha
  int pieceType = -1;

  // Condicionais de disponibilidade
  int basicAvailable = game->players[botId].baseCount > 0;
  int portalAvailable = game->players[botId].portalCount > 0;
  int explosiveAvailable = game->players[botId].explosiveCount > 0;

  int availableOptions[3];
  int optionsCont = 0;

  // Logica da ecolha de peça do bot
  if (basicAvailable) {
    availableOptions[optionsCont] = 0;
    optionsCont++;
  }
  if (portalAvailable ) {
    availableOptions[optionsCont] = 1;
    optionsCont++;
  }
  if (explosiveAvailable) {
    availableOptions[optionsCont] = 2;
    optionsCont++;
  }
  pieceType = availableOptions[rand() % optionsCont];
  int chosenCol = rand() % 7;
  
  botPlayMessage(game->players[botId].name, pieceType, chosenCol);
  
  BotChoice choice = {pieceType, chosenCol};
  return choice;
}