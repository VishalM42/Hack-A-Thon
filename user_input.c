#include "Header.h"

void clear_screen(void)
{
	printf("\n");
	system("pause");
	system("cls");
}


//This function asks the user if they want the loot randomly selected, how much of each loot they want, and the quality of loot and total loot
void get_input(int* choice, int* lootTier, int* totalItems, int* one_hand, int* two_hand, int* one_range, int* two_range)
{
	int decision = 0;
	int temp;

	do
	{
		printf("Welcome to the DND Loot Generator also known as DLG\n\nWould you like your loot randomly generated or hand picked?\n\nInput 1 for RNG\nInput 2 for hand selected\n");
		scanf(" %d", &decision);
		clear_screen();
	} while (decision < 1 || decision > 2);
	*choice = decision;

	if (decision == 1)
	{
		do
		{
			printf("How many items would you like generated(1-100)?\n");
			scanf(" %d", &temp);
			clear_screen();
		} while (temp < 1 || temp > 100);
		*totalItems = temp;
		temp = 0;
	}

	if (decision == 2)
	{
		do
		{
			printf("How many One Handed Melee Weapons do you want generated?\n");
			scanf(" %d", &temp);
		} while (temp < 0);
		*one_hand = temp;
		*totalItems += temp;
		temp = 0;
		do
		{
			printf("How many Two Handed Melee Weapons do you want generated?\n");
			scanf(" %d", &temp);
		} while (temp < 0);
		*two_hand = temp;
		*totalItems += temp;
		temp = 0;
		do
		{
			printf("How many One Handed Ranged Weapons do you want generated?\n");
			scanf(" %d", &temp);
		} while (temp < 0);
		*one_range = temp;
		*totalItems += temp;
		temp = 0;
		do
		{
			printf("How many Two Handed Ranged Weapons do you want generated?\n");
			scanf(" %d", &temp);
		} while (temp < 0);
		*two_range = temp;
		*totalItems += temp;
		temp = 0;
		clear_screen();
	}

	do
	{

		printf("Each object will run a check in decending order to determine their rarity.  If all checks are failed the weapon will be common.");
		printf("\nTier 10: Each object has a\n   10 percent chance of being Legendary\n   15 percent chance of being Rare\n   20 percent chance of being Uncommon");
		printf("\n\nTier 20: Each object has a\n   20 percent chance of being Legendary\n   30 percent chance of being Rare\n   40 percent chance of being Uncommon");
		printf("\n\nTier 30: Each object has a\n   30 percent chance of being Legendary\n   45 percent chance of being Rare\n   60 percent chance of being Uncommon");
		printf("\n\nTier 40: Each object has a\n   40 percent chance of being Legendary\n   60 percent chance of being Rare\n   80 percent chance of being Uncommon");
		printf("\n\nTier 50: Each object has a\n   50 percent chance of being Legendary\n   75 percent chance of being Rare\n   100 percent chance of being Uncommon");
		printf("\n\nWhat tier of generation do you want(1-50)?\n");
		scanf(" %d", &temp);
		clear_screen();
	} while (temp < 1 || temp > 50);
	*lootTier = temp;

}