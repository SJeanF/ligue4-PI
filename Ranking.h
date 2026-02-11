#ifndef RANKING_H
#define RANKING_H

typedef struct {
    char name[50];
    int rounds;
} RankingEntry;

void addRounds(char name[], int rounds);

void printRanking();

#endif
