#include "Game.h"
#include "GameAux.h"
#include "VerifyWin.h"
#include <string.h>
#include <stdio.h>

void initializeGame(Game* game) {
    game->players[0].name[0] = '\0';
    game->players[0].symbol = '\0';
    game->players[1].name[0] = '\0';
    game->players[1].symbol = '\0';
    game->roundCount = 0;
    fillTable(7, 6, game->table);
}

void setPlayer(Game* game, char name[], char symbol, int player) {
    if (player == 1) {
        strcpy(game->players[0].name, name);
        game->players[0].symbol = symbol;
    } else if (player == 2) {
        strcpy(game->players[1].name, name);
        game->players[1].symbol = symbol;
    }
}

int playRound(Game* game) {
    game->roundCount++;
    printf("\nRound %d começou\n", game->roundCount);

    for (int i = 0; i < 2; i++) {
        int col = 0;

        printf("É a vez de %s\n", game->players[i].name);
        printf("Tabela:\n");
        showTable(7, 6, game->table);
        printf("Escolha a coluna: ");
        scanf("%d", &col);
        col--; // 0 passa a ser a primeira coluna

        int row = addPiece(7, 6, game->table, col, game->players[i]);
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

void playGame(Game* game) {
    while (playRound(game) != 1) {

    }
}
