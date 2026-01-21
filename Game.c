#include "Game.h"
#include "GameAux.h"
#include "VerifyWin.h"
#include <stdio.h>
#include <string.h>

void initializeGame(Game *game) {
  for (int i = 0; i < 2; i++) {
    game->players[i].name[0] = '\0';
    game->players[i].symbol = '\0';
    game->players[i].baseCount = 0;
    game->players[i].portalCount = 0;
    game->players[i].explosiveCount = 0;
  }
  game->roundCount = 0;
  fillTable(7, 6, game->table);
}

void setPlayer(Game *game, char name[], char symbol, int player) {
  if (player == 1) {
    strcpy(game->players[0].name, name);
    game->players[0].symbol = symbol;
  } else if (player == 2) {
    strcpy(game->players[1].name, name);
    game->players[1].symbol = symbol;
  }
}

int playRound(Game *game) {
  game->roundCount++;
  printf("\nRound %d começou\n", game->roundCount);

  for (int i = 0; i < 2; i++) {
    int col = 0;

    printf("\nÉ a vez de %s\n", game->players[i].name);
    printf("Tabela:\n");
    showTable(7, 6, game->table);
    printf("Escolha a coluna: ");
    scanf("%d", &col);
    col--; // 0 passa a ser a primeira coluna

    int row = addPiece(7, 6, game->table, col, game->players[i], 0);
    char result = verifyLocalWin(7, 6, game->table, row, col);

    if (result != '\0') {
      showTable(7, 6, game->table);
      printf("%s venceu!\n", game->players[i].name);
      return 1;
      break;
    }
  }

  return 0;
}

void playGame(Game *game) {
  int choice = 0;

  printf("---Ligue 4 - SPECIAL EDITION---\n");
  printf("\nSeja bem-vindo ao Ligue 4! blábláblá.\n\n");
  printf("[1] Jogar\n");
  printf("[2] Sair\n");
  printf("Escolha: ");
  scanf("%d", &choice);

  while (1) {

    if (choice == 1) {
      initializeGame(game);

      printf("\n-----Jogador 1-----\n");
      printf("Nome: ");
      scanf("%s", game->players[0].name);
      printf("Simbolo: ");
      scanf(" %c", &game->players[0].symbol);

      printf("\n-----Jogador 2-----\n");
      printf("Nome: ");
      scanf("%s", game->players[1].name);
      printf("Simbolo: ");
      scanf(" %c", &game->players[1].symbol);

      while (playRound(game) != 1) {
      }

      printf("\nVocê deseja continuar jogando? \n");
      printf("[1] Sim\n");
      printf("[2] Não\n");
      printf("Escolha: ");
      scanf("%d", &choice);
    }

    if (choice == 2) {
      printf("\nObrigado por jogar!\n");
      return;
    }
  }
}
