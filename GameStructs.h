#ifndef GAMESTRUCTS_H
#define GAMESTRUCTS_H

typedef struct {
  char symbol;
} Position;

typedef struct {
  char *symbol;
  char name[50];
} Player;

typedef struct {
  char symbol;
  int cont;
} SymbolCont;

#endif // GAMESTRUCTS_H
