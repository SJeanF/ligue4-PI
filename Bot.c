#include "Bot.h"
#include <stdlib.h>

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
