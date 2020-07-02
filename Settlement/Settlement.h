#ifndef SETTLEMENT
#define SETTLEMENT

#define MAX_NAME_LEN 1024
#define SHORT_GAME 250
#define MED_GAME 500
#define LONG_GAME 1000
#define GAME_VER 0.1

typedef struct Settlement
{
	char settlementName[MAX_NAME_LEN];
	char leaderName[MAX_NAME_LEN];
	char leaderTitle[MAX_NAME_LEN];

	int daysLeft;

	// Pressing Matters
	int isResearching;
	int finishedResearch;
	int finishedRecruitment;
	int finishedConstruction;
	int finishedUpgrade;

	int raidSpotted;
	int daysTillRaid;

	int population;
	int happiness;
	int numBeds;
	int employedPops;

	char weather[MAX_NAME_LEN];
	char manaWind[MAX_NAME_LEN];

	int woodStore;
	int woodProd;
	int woodMax;

	int stoneStore;
	int stoneProd;
	int stoneMax;

	int oreStore;
	int oreProd;
	int oreMax;

	int manaStore;
	int manaProd;
	int manaMax;

	int foodStore;
	int foodProd;
	int foodMax;
}Set;

typedef struct LandInfo
{
	char biome[MAX_NAME_LEN];

	int hasRiver;
	int hasCoastline;

	int numEnemies;

	int numTrees;
	int numStone;
	int numOres;
	int amountMana;

	int fertility;
	int numAnimals;

	int buildDifficulty;
}Land;

typedef struct Buildings
{

}Build;

typedef struct Units
{

}Unit;

#endif
