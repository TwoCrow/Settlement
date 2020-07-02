#ifndef INITIALIZE
#define INITIALIZE

char *pickRandomBiome(void);

Land *initLand(void);

void printReports(Land *land, Set *settlement);

void initSettlement(Set *settlement);

void pickLocation(Land *land, Set *settlement);

void printStartMessage(Set *settlement);

void initGame(Set *settlement);

#endif
