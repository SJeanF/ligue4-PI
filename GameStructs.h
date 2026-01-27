#ifndef GAMESTRUCTS_H
#define GAMESTRUCTS_H

typedef struct {
  char symbol;
  int pieceType;
  int isWin;
} Position;

typedef struct {
  char symbol;
  char name[50];
  int baseCount;
  int portalCount;
  int explosiveCount;
  int isBot;
} Player;

typedef struct {
  char symbol;
  int cont;
  int coordinates[7][2]
} SymbolCont;

#endif // GAMESTRUCTS_H
