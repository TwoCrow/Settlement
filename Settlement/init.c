#include "Settlement.h"
#include "start.h"
#include "reports.h"
#include "manage.h"
#include "init.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *pickRandomBiome(void)
{
	char *biome = malloc(sizeof(char) * MAX_NAME_LEN + 1);
	int startBiome = (rand() % 6) + 1;

	if (startBiome == 1)
	{
		strcpy(biome, "Grassland");
	}
	else if (startBiome == 2)
	{
		strcpy(biome, "Forest");
	}
	else if (startBiome == 3)
	{
		strcpy(biome, "Desert");
	}
	else if (startBiome == 4)
	{
		strcpy(biome, "Tundra");
	}
	else if (startBiome == 5)
	{
		strcpy(biome, "Mountain");
	}
	else if (startBiome == 6)
	{
		strcpy(biome, "Swampland");
	}

	return biome;
}

Land *initLand(void)
{
	Land *land = malloc(sizeof(Land));
	char biome[MAX_NAME_LEN];

	strcpy(biome, pickRandomBiome());

	int hasRiver = rand() % 2;          // 1 = Has river, 0 = No river
	int hasCoastline = rand() % 2;      // 1 = Has coastline, 0 = No coastline
	int numEnemies = (rand() % 11) + 1; // 1 = Very few, 10 = Very many

	// These values are dependent on the biome.
	int numTrees, numStone, numOres;    // Number of available materials
	int fertility, numAnimals;          // Number of available food sources
	int buildDifficulty;                // Difficulty of building structures,
																			// 1 = Very easy, 10 = Very difficult

  strcpy(land->biome, biome);
	land->hasRiver = hasRiver;
	land->hasCoastline = hasCoastline;
	land->numEnemies = numEnemies;

	if (strcmp(biome, "Grassland") == 0)
	{
		strcpy(land->biome, "Grassland");
		land->numTrees = rand() % 4 + 1;
		land->numStone = rand() % 5 + 1;
		land->numOres = rand() % 3 + 1;
		land->amountMana = rand() % 10 + 1;
		land->fertility = rand() % 4 + 7;
		land->numAnimals = rand() % 5 + 1;
		land->buildDifficulty = rand() % 2 + 1;
	}
	else if (strcmp(biome, "Forest") == 0)
	{
		strcpy(land->biome, "Forest");
		land->numTrees = rand() % 3 + 8;
		land->numStone = rand() % 3 + 1;
		land->numOres = rand() % 4 + 1;
		land->amountMana = rand() % 10 + 1;
		land->fertility = rand() % 5 + 4;
		land->numAnimals = rand() % 4 + 5;
		land->buildDifficulty = rand() % 3 + 3;
	}
	else if (strcmp(biome, "Desert") == 0)
	{
		strcpy(land->biome, "Desert");
		land->numTrees = rand() % 2 + 1;
		land->numStone = rand() % 4 + 6;
		land->numOres = rand() % 2 + 9;
		land->amountMana = rand() % 10 + 1;
		land->fertility = rand() % 2 + 2;
		land->numAnimals = rand() % 2 + 2;
		land->buildDifficulty = rand() % 5 + 3;
	}
	else if (strcmp(biome, "Tundra") == 0)
	{
		strcpy(land->biome, "Tundra");
		land->numTrees = rand() % 3 + 4;
		land->numStone = rand() % 5 + 3;
		land->numOres = rand() % 4 + 2;
		land->amountMana = rand() % 10 + 1;
		land->fertility = rand() % 3 + 1;
		land->numAnimals = rand() % 4 + 2;
		land->buildDifficulty = rand() % 5 + 2;
	}
	else if (strcmp(biome, "Mountain") == 0)
	{
		strcpy(land->biome, "Mountain");
		land->numTrees = rand() % 3 + 3;
		land->numStone = rand() % 2 + 9;
		land->numOres = rand() % 2 + 6;
		land->amountMana = rand() % 10 + 1;
		land->fertility = rand() % 2 + 2;
		land->numAnimals = rand() % 3 + 2;
		land->buildDifficulty = rand() % 2 + 9;
	}
	else if (strcmp(biome, "Swampland") == 0)
	{
		strcpy(land->biome, "Swampland");
		land->numTrees = rand() % 6 + 2;
		land->numStone = rand() % 2 + 3;
		land->numOres = rand() % 2 + 3;
		land->amountMana = rand() % 10 + 1;
		land->fertility = rand() % 3 + 4;
		land->numAnimals = rand() % 2 + 4;
		land->buildDifficulty = rand() % 4 + 6;
	}

	return land;
}

void printReports(Land *land, Set *settlement)
{
	printf("\n---------------------------------------------REPORT---------------------------------------------");
	printf("\nYou halt your people's journey for the day, and send out your best scouts to survey the area.\n");
	printf("\"Lord %s, I have a report for you!\" says one of your scouts.\n\n", settlement->leaderName);

	printf("We are currently in a %s biome.\n", land->biome);

	if (land->hasRiver == 1 && land->hasCoastline == 1)
	{
		printf("A river runs through the area, and empties out into a nearby coast.\n");
	}
	else if (land->hasRiver == 1)
	{
		printf("A river runs through the area.\n");
	}
	else if (land->hasCoastline == 1)
	{
		printf("There is a nearby coastline.\n");
	}

	printEnemyReport(land);
	printTreeReport(land);
	printStoneReport(land);
	printOreReport(land);
	printManaReport(land);
	printFertilityReport(land);
	printAnimalReport(land);
	printBuildReport(land);

	printEvaluation(land, settlement);
}

// Initializes the rest of the members of the Settlement struct.
void initSettlement(Set *settlement)
{
	settlement->isResearching = 0;
	settlement->finishedResearch = 0;
	settlement->finishedRecruitment = 0;
	settlement->finishedConstruction = 0;
	settlement->finishedUpgrade = 0;

	settlement->raidSpotted = 0;
	settlement->daysTillRaid = -1;

	settlement->population = 100;
	settlement->happiness = 75;
	settlement->numBeds = 0;
	settlement->employedPops = 0;

	strcpy(settlement->weather, "Clear");
	strcpy(settlement->manaWind, "Average");

	settlement->woodStore = 100;
	settlement->woodProd = 0;
	settlement->woodMax = 500;

	settlement->stoneStore = 50;
	settlement->stoneProd = 0;
	settlement->stoneMax = 250;

	settlement->oreStore = 50;
	settlement->oreProd = 0;
	settlement->oreMax = 250;

	settlement->manaStore = 0;
	settlement->manaProd = 0;
	settlement->manaMax = 100;

	settlement->foodStore = 100;
	settlement->foodProd = 0;
	settlement->foodMax = 250;
}

void pickLocation(Land *land, Set *settlement)
{
	int isValid = 1;
	char choice, cont;

	printf("You end your days' travels, and come upon the first area that could be a potential\n");
	printf("candidate for the SETTLEMENT.\n");
	printf("\n\n(Input any key and press enter to continue...)\n\n");

	scanf(" %c", &cont);

	while (choice != 'Y' && choice != 'y')
	{
		if (isValid)
		{
			printReports(land, settlement);
			printf("\nWould you like to settle here? (Y / N):\n");
		}

		scanf(" %c", &choice);

		if (choice == 'N' || choice == 'n')
		{
			printf("\nYou order your people to move to the next location.\n");
			printf("The journey takes a full day. %d DAYS LEFT.\n", --(settlement->daysLeft));

			land = initLand();
			isValid = 1;
		}
		else if (choice == 'Y' || choice == 'y')
		{
			printf("You order your tribe to settle at this location.\n");
			printf("They begin to unload their things and set up temporary tents and stockpiles.\n");
			printf("It takes them a full day to do so. %d DAYS LEFT.\n\n", --(settlement->daysLeft));

			initSettlement(settlement);
			manageSettlement(land, settlement);

			isValid = 1;
		}
		else
		{
			printf("Invalid input. Please choose either 'Y' or 'N' (without quotations)\n");
			isValid = 0;
		}
	}
}

void printStartMessage(Set *settlement)
{
	printf("----------------------------------------START----------------------------------------\n\n");
	printf("You land in the middle of a human encampment, and approach a group huddled around\n");
	printf("a campfire. \"I am %s the %s. The gods have sent me. I am here to lead you all to \n", settlement->leaderName, settlement->leaderTitle);
	printf("safety,\" you say. The group looks unsure, but guides you to their leader.\n\n");

	printf("After talking for a while, and showing him your godly abilities as proof, he \n");
	printf("relinquishes his role as leader to you.\n\n");

	printf("You emerge from the leader's tent to address the downtrodden masses of people.\n");
	printf("\"I swear to my family in the heavens above that I shall lead you all to safety!\n");
	printf("We shall construct a SETTLEMENT that will stand proud against the hordes of \n");
	printf("the vile UNDERWORLDERS. Tomorrow, we shall leave to set out for a place to \n");
	printf("establish this grand new SETTLEMENT. Rest well, my people.\"\n\n");

	printf("In the morning, your people pack up their tents and follow you to a new land.\n");
	printf("Hopefully, you will find a viable place to start your SETTLEMENT.\n\n");
}

void initGame(Set *settlement)
{
	Land *land;

	printStartMessage(settlement);
	land = initLand();
	pickLocation(land, settlement);
}
