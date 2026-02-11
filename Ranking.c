#include "Ranking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addRounds(char name[], int rounds) {
  FILE *file = fopen("ranking.txt", "r");

  // Cria o arquivo se ele não existir
  if (file == NULL) {
    file = fopen("ranking.txt", "w");

    fprintf(file, "------,999\n------,999\n------,999\n");

    fclose(file);
    file = fopen("ranking.txt", "r");

    if (file == NULL) {
      printf("Erro ao criar o arquivo de ranking.\n");
      return;
    }
  }

  char rows[100];
  RankingEntry players[3];
  int i = 0;

  while (fgets(rows, sizeof(rows), file) != NULL) {

    rows[strcspn(rows, "\n")] = 0;

    // Pega o nome
    char *token = strtok(rows, ",");

    if (token != NULL) {
      strcpy(players[i].name, token);

      // Pega a pontuação
      token = strtok(NULL, ",");
      players[i].rounds = atoi(token);

      i++;
    }
  }

  // Reescrever lista com pontuação nova (se menor que alguma existente)
  for (i = 0; i < 3; i++) {
    if (rounds < players[i].rounds) {

      // DESLOCAMENTO CORRETO: Começa de trás para frente
      for (int j = 2; j > i; j--) {
        strcpy(players[j].name, players[j - 1].name);
        players[j].rounds = players[j - 1].rounds;
      }

      // Agora que o espaço na posição 'i' foi liberado, inserimos o novo
      strcpy(players[i].name, name);
      players[i].rounds = rounds;

      break; // Sai do loop após inserir
    }
  }

  // Reescrever arquivo
  fclose(file);
  file = fopen("ranking.txt", "w");

  for (i = 0; i < 3; i++) {
    fprintf(file, "%s,%d\n", players[i].name, players[i].rounds);
  }

  fclose(file);
}

void printRanking() {
  FILE *file = fopen("ranking.txt", "r");

  if (file == NULL) {
    printf("O Hall dos campeões ainda não existe, é preciso que alguém jogue o jogo para começar");
    return;
  }

  char rows[100];
  RankingEntry players[3];
  int i = 0;


  while (fgets(rows, sizeof(rows), file) != NULL) {

    rows[strcspn(rows, "\n")] = 0;

    // Pega o nome
    char *token = strtok(rows, ",");

    if (token != NULL) {
      strcpy(players[i].name, token);

      // Pega a pontuação
      token = strtok(NULL, ",");
      players[i].rounds = atoi(token);

      i++;
    }
  }

  printf("\n------HALL DOS CAMPEÕES------\n\n");
  for (int i = 0; i < 3; i++) {
    printf("Jogador: %s, Rounds: %d\n", players[i].name, players[i].rounds);
  }
  printf("\n-----------------------------\n");

  fclose(file);
}
