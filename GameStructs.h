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
  int x;
  int y;
} SymbolCoordinates;

typedef struct {
  char symbol;
  int cont;
  SymbolCoordinates coordinates[7];
} SymbolCont;

#endif // GAMESTRUCTS_H
