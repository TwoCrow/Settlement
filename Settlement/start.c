#include "Settlement.h" // Constants and Structs
#include "start.h"
#include "init.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prompt the player to make some decisions that will affect the game.
// Returns the days left in the game.
int setupGame(void)
{
	int isValid = 0;
	int gameLength, daysLeft;

	while (!isValid)
	{
		printf("Pick the length of the game:\n");
		printf("1. Short (%d Days)\n", SHORT_GAME);
		printf("2. Medium (%d Days)\n", MED_GAME);
		printf("3. Long (%d Days)\n", LONG_GAME);

		scanf("%d", &gameLength);
		isValid = 1;

		if (gameLength < 1 || gameLength > 3)
		{
			printf("Invalid input. Please pick a value 1 - 3\n");
			isValid = 0;
		}
	}

	if (gameLength == 1)
	{
		daysLeft = SHORT_GAME;
	}
	else if (gameLength == 2)
	{
		daysLeft = MED_GAME;
	}
	else if (gameLength == 3)
	{
		daysLeft = LONG_GAME;
	}

	printf("\n");

	return daysLeft;
}

// Dynamically allocates space for a new Settlement struct.
// This function will only initialize the first two name members of the struct using user input.
// It then returns a pointer to the new struct.
Set *nameSettlement(void)
{
	Set *settlement = malloc(sizeof(Set));
	char setName[MAX_NAME_LEN];
	char charName[MAX_NAME_LEN];
	char charTitle[MAX_NAME_LEN];

	printf("NOTE: One word allowed per entry. No spaces.\n\n");

	printf("What will the name of your settlement be?\n");
	scanf("%s", setName);

	printf("What is the name of your leader?\n");
	scanf("%s", charName);

	printf("What is your leader's title? (i.e. Harold the Brave)\n");
	scanf("%s", charTitle);

	printf("\n\nYour leader, %s the %s, leads the settlement of %s.\n\n", charName, charTitle, setName);

	strcpy(settlement->settlementName, setName);
	strcpy(settlement->leaderName, charName);
	strcpy(settlement->leaderTitle, charTitle);

	return settlement;
}

// Lets the player configure the starting conditions for a new game.
void startGame(void)
{
	Set *settlement;
	int daysLeft;

	daysLeft = setupGame();
	settlement = nameSettlement();

	settlement->daysLeft = daysLeft;

	initGame(settlement);
}

// TODO
// Implement with file I/O
void loadGame(void)
{
	printf("Sorry! This feature isn't supported yet.\n\n");
}

// Prints the backstory of the game.
void printBackstory(void)
{
	printf("\n-------------------------------BACKSTORY-------------------------------\n\n");
	printf("HALDA, a land forged by the gods. Its population of humans were their children. \n");
	printf("Under their holy watch, HALDA was prosperous for hundreds of millennia.\n\n");

	printf("But not all in the land were happy with the rule of the gods. Some claimed \n");
	printf("they could attain greater freedom without the deities looking over them.\n");
	printf("They claimed the gods held back the progress of magic on purpose.\n\n");

	printf("These disgruntled people attempted an uprising against their creators.\n");
	printf("Distraught, the gods were unsure of how to proceed. They could not bring \n");
	printf("themselves to harm their children. Instead, the two sides reconciled.\n");
	printf("The gods agreed to give the discontents the caves of HALDA as a home, and in\n");
	printf("exchange, the newly-named UNDERWORLDERS lost the gaze of the gods.\n\n");

	printf("At first, the UNDERWORLDERS were quite pleased. They set to work on studying\n");
	printf("magic, mapping the vast UNDERWORLD, and growing their numbers and supplies.\n");
	printf("But a horrible magical experiment went awry, and corrupted the \n");
	printf("UNDERWORLDERS. They became awful, twisted creatures filled with \n");
	printf("hatred. They began to resent both their creators, and the deal \n");
	printf("they struck so many years ago. They resented the surface-dwellers, and \n");
	printf("the sunlight that they squandered.\n\n");

	printf("So the UNDERWORLDERS invaded en masse. They ravaged cities and towns \n");
	printf("with no thought for human life. They murdered and pillaged senselessly.\n");
	printf("Human society fell to ruin, and its few survivors scattered to the winds.\n");
	printf("To stay alive, these survivors resorted to becoming highly-mobile hunters \n");
	printf("and gatherers, constantly on alert. Even still, their numbers struggled \n");
	printf("as the UNDERWORLDERS began establishing a strong surface presence.\n\n");

	printf("After nearly a decade of UNDERWORLDER rule, the gods are close to \n");
	printf("having a large enough army to contend with the UNDERWORLDER forces.\n");
	printf("They need only a last bastion of hope in the realm to protect its \n");
	printf("remaining few citizens. So they have sent you, a mighty demi-god capable of \n");
	printf("establishing this final SETTLEMENT. You must craft this SETTLEMENT in \n");
	printf("time for the arrival of the gods' armies, and keep its people safe.\n\n");

	printf("-------------------------------BACKSTORY-------------------------------\n\n");
}

// TODO
// May not be a viable option in the final version.
void gameSettings(void)
{
	printf("Sorry! There currently aren't any options to choose from.\n\n");
}

// Prompts the player for inputs regarding the options on the start menu.
// It calls requisite functions based on what the player chooses.
void playerInput(void)
{
	int choice;

	scanf("%d", &choice);

	while (choice != 5)
	{
		// Start game
		if (choice == 1)
		{
			startGame();
		}
		// Load game
		else if (choice == 2)
		{
			loadGame();
		}
		// Backstory
		else if (choice == 3)
		{
			printBackstory();
		}
		// Settings
		else if (choice == 4)
		{
			gameSettings();
		}
		// Exit
		else if (choice == 5)
		{
			exit(0);
		}
		// Invalid input
		else
		{
			printf("Invalid input. Please input a valid integer 1 - 5 to choose an option.\n");
		}

		printStartMenu();
		scanf("%d", &choice);
	}
}

// Prints the start menu for the player to choose from some basic options.
// They can do one of five things:
// 1. Start a new game.
// 2. Load up an existing save.
// 3. Read the backstory for the game, which provides some fun context.
// 4. Tweak the settings of the game (CONCEPTUAL, NEEDS IMPLEMENTATION)
// 5. Quit the program
// This function is only used to print this menu screen. It does not accept inputs.
void printStartMenu(void)
{
	printf("\n---------------------------------------------------\n");
	printf("Choose an option:\n\n");
	printf("1. START A New Game\n");
	printf("2. LOAD An Existing Game (NOT IMPLEMENTED)\n");
	printf("3. READ the Backstory\n");
	printf("4. TWIDDLE With the Settings (NOT IMPLEMENTED)\n");
	printf("5. QUIT the Game\n");
	printf("---------------------------------------------------\n\n");
}

// This function does nothing but print the game's title and then call the printStartMenu()
// function. For all intents and purposes, it is the main() of this file.
void printTitleScreen(void)
{
	printf("SETTLEMENT v%.1f by Patrick \"Lavaman\" Sherbondy\n", GAME_VER);

	printStartMenu();
	playerInput();
}
