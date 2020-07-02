#include "Settlement.h"
#include "reports.h"

#include <stdio.h>

void printEnemyReport(Land *land)
{
	if (land->numEnemies == 1)
	{
		printf("Thankfully, there appears to be very low Underworlder activity in the area.\n");
	}
	else if (land->numEnemies > 1 && land->numEnemies < 5)
	{
		printf("Underworlder activity in the area is lower than average.\n");
	}
	else if (land->numEnemies == 5)
	{
		printf("The number of Underworlders in the area is about average.\n");
	}
	else if (land->numEnemies > 5 && land->numEnemies < 10)
	{
		printf("Underworlder activity is higher here than most areas.\n");
	}
	else if (land->numEnemies == 10)
	{
		printf("This area is a hotbed of Underworlders! We must be very close to a Stronghold!\n");
	}
}

void printTreeReport(Land *land)
{
	if (land->numTrees == 1)
	{
		printf("The number of trees in this area is abysmally low.\n");
	}
	else if (land->numTrees > 1 && land->numTrees < 5)
	{
		printf("There are sparse collections of trees in the area.\n");
	}
	else if (land->numTrees == 5)
	{
		printf("There is an average amount of trees.\n");
	}
	else if (land->numTrees > 5 && land->numTrees < 10)
	{
		printf("There is an abundance of trees.\n");
	}
	else if (land->numTrees == 10)
	{
		printf("It's impossible to see the sky with the amount of trees around us!\n");
	}
}

void printStoneReport(Land *land)
{
	if (land->numStone == 1)
	{
		printf("The only stone we found was a loose collection of pebbles.\n");
	}
	else if (land->numStone > 1 && land->numStone < 5)
	{
		printf("There is a small amount of usable stone.\n");
	}
	else if (land->numStone == 5)
	{
		printf("There is an average amount of available stone.\n");
	}
	else if (land->numStone > 5 && land->numStone < 10)
	{
		printf("There is quite a bit of usable stone around us.\n");
	}
	else if (land->numStone == 10)
	{
		printf("My boots are filled with pebbles from the huge amount of stone!\n");
	}
}

void printOreReport(Land *land)
{
	if (land->numOres == 1)
	{
		printf("Ore is incredibly sparse.\n");
	}
	else if (land->numOres > 1 && land->numOres < 5)
	{
		printf("We've found a few, small veins of usable ore.\n");
	}
	else if (land->numOres == 5)
	{
		printf("The amount of ore around here is about average.\n");
	}
	else if (land->numOres > 5 && land->numOres < 10)
	{
		printf("There are many pockets of ore in the area.\n");
	}
	else if (land->numOres == 10)
	{
		printf("We've hit the motherlode! We'll never be short on ore here.\n");
	}

	if (land->hasRiver == 1 && land->numOres >= 5)
	{
		printf("Additionally, the nearby river glimmers with ore!\n");
	}
}

void printManaReport(Land *land)
{
	if (land->amountMana == 1)
	{
		printf("The currents of mana here are incredibly weak.\n");
	}
	else if (land->amountMana > 1 && land->amountMana < 5)
	{
		printf("Mana currents are noticeable, but nothing special.\n");
	}
	else if (land->amountMana == 5)
	{
		printf("The currents of mana here are rather decent.\n");
	}
	else if (land->amountMana > 5 && land->amountMana < 10)
	{
		printf("There are some powerful currents of mana in this area.\n");
	}
	else if (land->amountMana == 10)
	{
		printf("The mana currents here are incredible! The air crackles with raw magic power!\n");
	}
}

void printFertilityReport(Land *land)
{
	if (land->fertility == 1)
	{
		printf("The land is barren and doesn't sustain flora very well.\n");
	}
	else if (land->fertility > 1 && land->fertility < 5)
	{
		printf("The land is sub-par for foraging and farming.\n");
	}
	else if (land->fertility == 5)
	{
		printf("The land decently sustains its population of flora.\n");
	}
	else if (land->fertility > 5 && land->fertility < 10)
	{
		printf("The land is quite arable. It could sustain a good number of crops.\n");
	}
	else if (land->fertility == 10)
	{
		printf("The land is incredibly fertile! Plants seem to grow right before your very eye.\n");
	}
}

void printAnimalReport(Land *land)
{
	if (land->numAnimals == 1)
	{
		printf("The largest animal I've seen around here has been a tiny beetle.\n");
	}
	else if (land->numAnimals > 1 && land->numAnimals < 5)
	{
		printf("Animals are infrequent, but present.\n");
	}
	else if (land->numAnimals == 5)
	{
		printf("There is an average amount of animals in the area.\n");
	}
	else if (land->numAnimals > 5 && land->numAnimals < 10)
	{
		printf("The population of fauna is somewhat impressive.\n");
	}
	else if (land->numAnimals == 10)
	{
		printf("There are animals frollicking everywhere! The fauna population here is immense!\n");
	}
}

void printBuildReport(Land *land)
{
	// This print statement helps set the longer build reports apart from the other reports.
	printf("\n");

	if (land->buildDifficulty == 1)
	{
		printf("It is incredibly easy to build on this land! We could construct new buildings here\n");
		printf("in half the usual time.\n");
	}
	else if (land->buildDifficulty > 1 && land->buildDifficulty < 5)
	{
		printf("New buildings can easily be built on this land.\n");
	}
	else if (land->buildDifficulty == 5)
	{
		printf("The soil here presents no challenge to building, but also doesn't make it easier.\n");
		printf("It is perfectly average for construction.\n");
	}
	else if (land->buildDifficulty > 5 && land->buildDifficulty < 10)
	{
		printf("It would be somewhat difficult to make new structures on this land, and would take us \n");
		printf("longer than usual to complete construction.\n");
	}
	else if (land->buildDifficulty == 10)
	{
		printf("This land is unfriendly to new constructions. It would take us twice the usual time\n");
		printf("to make new buildings.\n");
	}
}

// Prints the evaluation score for a given area of land.
void printEvaluation(Land *land, Set *name)
{
	int totalScore = 0;

	totalScore += land->hasRiver * 3 + land->hasCoastline * 3;
	totalScore -= land->numEnemies;

	if (land->numTrees >= 5)
	{
		totalScore += land->numTrees;
	}
	else
	{
		totalScore -= land->numTrees;
	}

	if (land->numStone >= 5)
	{
		totalScore += land->numStone;
	}
	else
	{
		totalScore -= land->numStone;
	}

	if (land->numOres >= 5)
	{
		totalScore += land->numOres;
	}
	else
	{
		totalScore -= land->numOres;
	}

	if (land->amountMana >= 5)
	{
		totalScore += land->amountMana;
	}
	else
	{
		totalScore -= land->amountMana;
	}

	if (land->fertility >= 5)
	{
		totalScore += land->fertility;
	}
	else
	{
		totalScore -= land->fertility;
	}

	if (land->numAnimals >= 5)
	{
		totalScore += land->numAnimals;
	}
	else
	{
		totalScore -= land->numAnimals;
	}

	if (land->buildDifficulty >= 5)
	{
		totalScore += land->buildDifficulty;
	}
	else
	{
		totalScore -= land->buildDifficulty;
	}

	printf("\n");
	printf("Based on the land's features, this location has earned an Evaluation Score of %d\n\n", totalScore);

	if (totalScore <= 4)
	{
		printf("Lord %s, I would not at all recommend founding our SETTLEMENT here.\n", name->leaderName);
		printf("It will present some serious challenges to our developments\n");
	}
	else if (totalScore > 4 && totalScore < 10)
	{
		printf("Lord %s, this is a fairly average place to settle.\n", name->leaderName);
		printf("It will present some challenges, but is safer than most areas.\n");
	}
	else
	{
		printf("Lord %s! This is an exceptional place to found our SETTLEMENT!\n", name->leaderName);
		printf("We should find relative safety if we settle here.\n");
	}
}
