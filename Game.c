#include "Game.h"
#include "GameAux.h"
#include "Ranking.h"
#include "VerifyWin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeGame(Game *game) {
  for (int i = 0; i < 2; i++) {
    game->players[i].name[0] = '\0';
    game->players[i].symbol = '\0';
    game->players[i].baseCount = 21;
    game->players[i].portalCount = 0;
    game->players[i].explosiveCount = 0;
  }
  game->roundCount = 0;
  fillTable(7, 6, game->table);
}

void setPlayer(Player players[], int playerId) {
    printf("\n-----Jogador %d-----\n", playerId + 1);

    printf("Nome: ");
    scanf("%s", players[playerId].name);

    if (playerId > 0) {
        while (strcmp(players[playerId].name, players[playerId - 1].name) == 0) {
            printf("Erro: O nome nao pode ser igual ao do Jogador %d.\n", playerId);
            printf("Digite outro Nome: ");
            scanf("%s", players[playerId].name);
        }
    }

    printf("Simbolo: ");
    scanf(" %c", &players[playerId].symbol);

    if (playerId > 0) {
        while (players[playerId].symbol == players[playerId - 1].symbol) {
            printf("Erro: O simbolo nao pode ser igual ao do Jogador %d.\n", playerId);
            printf("Escolha outro Simbolo: ");
            scanf(" %c", &players[playerId].symbol);
        }
    }
    players[playerId].isBot = 0;
}

void selectGameMode(Game *game) {
  int gameMode = -1;
  while (gameMode == -1) {

    printf("\nModos de jogo disponiveis:\n");
    printf("[0] - Automático\n");
    printf("[1] - Um Jogador\n");
    printf("[2] - Dois Jogador\n");
    printf("Escolha: ");
    scanf("%d", &gameMode);

    if (gameMode < 0 || gameMode > 2) {
      printf("Opção não disponivel, por favor selecionar modo de jogo listado\n");
      gameMode = -1;
      continue;
    }
  }

  if (gameMode == 0) {
    strcpy(game->players[0].name, "Bot - 1");
    game->players[0].symbol = '#';
    game->players[0].isBot = 1;
    strcpy(game->players[1].name, "Bot - 2");
    game->players[1].symbol = '@';
    game->players[1].isBot = 1;
  } else if (gameMode == 1) {
    setPlayer(game->players, 0);

    // garantir que o bot não vai ter o mesmo nome/simbolo que o jogador
    if (strcmp(game->players[0].name, "Bot - 1") == 0) {
      strcpy(game->players[1].name, "Bot - 2");
    } else {
      strcpy(game->players[1].name, "Bot - 1");
    }

    if (game->players[0].symbol == '@') {
      game-> players[1].symbol = '#';
    } else {
      game->players[1].symbol = '@';
    }
    game->players[1].isBot = 1;
  } else if (gameMode == 2) {
    for (int i = 0; i < 2; i++) {
      setPlayer(game->players, i);
    }
  }
}

int playRound(Game *game) {
  game->roundCount++;
  printf("\n\n-----Round %d começou-----\n", game->roundCount);

  // Ganho de peças por rodada
  if (game->roundCount % 10 == 0) {
    printf("\nOs jogadores ganharam duas peças especiais!\n");

    for (int i = 0; i < 2; i++) {
      game->players[i].explosiveCount++;
      game->players[i].portalCount++;
    }
  }

  for (int i = 0; i < 2; i++) {
    int col = 0;

    printf("\nÉ a vez de %s\n", game->players[i].name);
    printf("Tabela:\n");
    showTable(7, 6, game->table);

    // Escolha do tipo da ficha
    int pieceType = -1;

    // Condicionais de disponibilidade
    int basicAvailable = game->players[i].baseCount > 0;
    int portalAvailable = game->players[i].portalCount > 0;
    int explosiveAvailable = game->players[i].explosiveCount > 0;

    if (game->players[i].isBot) {
      BotChoice choice = botPlay(game, i);

      pieceType = choice.pieceType;
      col = choice.chosenCol;

      botPlayMessage(game->players[i].name, pieceType, col);
    } else {
      printf("Fichas disponíveis:\n");
      printf("[0] Básicas: %d\n", game->players[i].baseCount);
      printf("[1] Portais: %d\n", game->players[i].portalCount);
      printf("[2] Explosivos: %d\n", game->players[i].explosiveCount);
      while (pieceType == -1) {
        printf("Escolha: ");
        scanf("%d", &pieceType);

        // Diminuição da quantidade de peças
        if (pieceType == 0 && basicAvailable)
          game->players[i].baseCount--;
        else if (pieceType == 1 && portalAvailable)
          game->players[i].portalCount--;
        else if (pieceType == 2 && explosiveAvailable)
          game->players[i].explosiveCount--;
        else {
          printf("\nFicha indisponível!\n");
          pieceType = -1;
        }
      }

      // Validação da coluna escolhida
      while (1) {
        printf("\nEscolha a coluna: ");
        scanf("%d", &col);

        if (col > 0 && col < 8) break;
        else {
          printf("Coluna invalida, por favor selecionar uma coluna entre 1 e 7\n");
          if (game->players[i].isBot) {}
        }
      }
      col--; // 0 passa a ser a primeira coluna
    }

    int row = addPiece(7, 6, game->table, col, game->players[i], pieceType); // falta fazer o jogador jogar denovo se a coluna estiver cheia
    char result = verifyLocalWin(7, 6, game->table, row, col);

    if (result != '\0') {
      showTable(7, 6, game->table);
      printf("%s venceu!\n", game->players[i].name);
      addRounds(game->players[i].name, game->roundCount);
      return 1;
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
  printf("[3] Hall dos campeões\n");
  printf("Escolha: ");
  scanf("%d", &choice);

  while (1) {

    if (choice == 1) {
      initializeGame(game);
      selectGameMode(game);

      while (playRound(game) != 1) {
      }

      printf("\nVocê deseja continuar jogando? \n");
      printf("[1] Sim\n");
      printf("[2] Não\n");
      printf("Escolha: ");
      scanf("%d", &choice);
    }
    else if (choice == 2) {
      printf("\nObrigado por jogar!\n");
      return;
    }
    else if (choice == 3) {
      printRanking();
      return;
    }
    else {
      while (!(choice == 1 || choice == 2 || choice == 3)) {
        printf("Opção invalida, por favor, digite uma das opções listadas\n");
        printf("\nVocê deseja continuar jogando? \n");
        printf("[1] Sim\n");
        printf("[2] Não\n");
        printf("[3] Hall dos campeões");
        printf("Escolha: ");
        scanf("%d", &choice);
      }
    }
  }
}
