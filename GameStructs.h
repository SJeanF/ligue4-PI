#ifndef GAMESTRUCTS_H
#define GAMESTRUCTS_H

typedef struct {
  char symbol;
  int pieceType;
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
} SymbolCont;

#endif // GAMESTRUCTS_H
