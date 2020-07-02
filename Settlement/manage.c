#include "Settlement.h"
#include "manage.h"

#include <stdio.h>
#include <stdlib.h>

void enterChoice(int choice, Land *land, Set *set)
{
	while (choice != 8)
	{
		if (choice == 1)
		{
			//manageConstruction();
		}
		else if (choice == 2)
		{
			//manageUnits();
		}
		else if (choice == 3)
		{
			//managePopulation();
		}
		else if (choice == 4)
		{
			//manageResearch();
		}
		else if (choice == 5)
		{
			//manageBuildings();
		}
		else if (choice == 6)
		{
			//proceedToNextDay();
		}
		else if (choice == 7)
		{
			//saveGame();
		}
		else if (choice == 8)
		{
			exit(0);
		}
		else
		{
			printf("Invalid input. Try again:\n");
			scanf(" %d", &choice);
		}
	}
}

void manageSettlement(Land *land, Set *set)
{
	int choice;

	while (choice != 8)
	{
		printf("The Settlement of %s | Lord %s the %s\n", set->settlementName, set->leaderName, set->leaderTitle);
		printf("---------------------------------------------------------------------\n");
		printf("Days Remaining: %d\n", set->daysLeft);
		printf("Settlement Population: %d | Settlement Happiness: %d\n", set->population, set->happiness);
		printf("Current Weather: %s | Current Mana Winds: %s\n", set->weather, set->manaWind);
		printf("Stored Wood: %d | Stored Stone: %d | Stored Ore: %d | Stored Mana: %d | Stored Food: %d\n", set->woodStore, set->stoneStore, set->oreStore, set->manaStore, set->foodStore);
		printf("Wood Prod/D: %d | Stone Prod/D: %d | Ore Prod/D: %d | Mana Prod/D: %d | Food Prod/D: %d\n", set->woodProd, set->stoneProd, set->oreProd, set->manaProd, set->foodProd);
		printf("---------------------------------------------------------------------\n\n");

		printf("Pressing Matters:\n");
		//printPressingMatters(set); // TODO

		printf("--------------------------------------------------\n");
		printf("What would you like to do?\n");
		printf("--------------------------------------------------\n");
		printf("1. Construct or upgrade a building.\n");
		printf("2. Manage your units.\n");
		printf("3. Manage your population.\n");
		printf("4. Select research.\n");
		printf("5. Manage buildings and resources.\n");
		printf("6. Proceed to the next day.\n\n");

		printf("7. Save the game.\n");
		printf("8. Quit the game.\n");
		printf("--------------------------------------------------\n");

		scanf(" %d", &choice);
		enterChoice(choice, land, set);
	}
}
