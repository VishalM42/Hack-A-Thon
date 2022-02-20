#include "Header.h"

int determineRarity(int lootTier)
{
	int factor = 0;
	factor = rand() % 100 + 1;
	if (factor <= (lootTier))
	{
		return 4;
	}
	else if (factor <= (lootTier * 1.5))
	{
		return 3;
	}
	else if (factor <= (lootTier * 2))
	{
		return 2;
	}
	return 1;
}

//char name[30];
//int kind; //1 one handed melee, 2 two handed melee, 3 one handed ranged, 4 two handed ranged
//int damageType; //1 is piercing, 2 is slashing, 3 is bludgeon
//int diceTotal; //total damage dice pre-modifier
//int diceType; //type of dice
void createWeaponRNG_OneHandM(int rarity, int size, Weapon OneHand[], Damage damage[], ToHit toHit[], Random random[])
{
	int i = 0;
	int modType = 0;
	int mod = 0;

	i = rand() % size;

	if (rarity == 1)
	{
		printf("\n %s, %d d%d damage\n\n", OneHand[i].name, OneHand[i].diceTotal, OneHand[i].diceType);
	}

	else if (rarity == 2)
	{
		modType = rand() % 100;
		if (modType < 60)
		{
			do {
				mod = rand() % 20;
			} while (random[mod].num != 1);
			printf("\n %s, %d d%d damage\n %s: %s\n\n", OneHand[i].name, OneHand[i].diceTotal, OneHand[i].diceType, random[mod].name, random[mod].desrption);
		}
		else if (modType >= 60 && modType < 80)
		{
			do {
				mod = rand() % 10;
			} while (damage[mod].plusDice < 1);
			printf("\n %s, %d d%d damage\n %s: + %d D%d damage\n\n", OneHand[i].name, OneHand[i].diceTotal, OneHand[i].diceType, damage[mod].name, damage[mod].plusDice, damage[mod].diceType);
		}
		else if (modType >= 80)
		{
			mod = 0;
			printf("\n %s, %d d%d damage\n %s: + %d D%d to hit\n\n", OneHand[i].name, OneHand[i].diceTotal, OneHand[i].diceType, toHit[mod].name, toHit[mod].plusDice, toHit[mod].diceType);
		}
	}

	else if (rarity == 3)
	{
		do {
			mod = rand() % 20;
		} while (random[mod].num != 1);
		printf("\n %s, %d d%d damage\n %s: %s\n", OneHand[i].name, OneHand[i].diceTotal, OneHand[i].diceType, random[mod].name, random[mod].desrption);

		if (modType < 50)
		{
			do {
				mod = rand() % 10;
			} while (damage[mod].plusDice < 1);
			printf(" %s: + %d D%d damage\n\n",  damage[mod].name, damage[mod].plusDice, damage[mod].diceType + 2);
		}
		else
		{
			mod = 0;
			printf(" %s: + %d D%d to hit\n\n",toHit[mod].name, toHit[mod].plusDice, toHit[mod].diceType + 2);
		}
	}

	else if (rarity == 4)
	{
		do {
			mod = rand() % 20;
		} while (random[mod].num != 1);
		printf("\n %s, %d d%d damage\n %s: %s\n", OneHand[i].name, OneHand[i].diceTotal, OneHand[i].diceType, random[mod].name, random[mod].desrption);

		do {
			mod = rand() % 10;
		} while (damage[mod].plusDice < 1);
		printf(" %s: + %d D%d damage\n", damage[mod].name, damage[mod].plusDice, damage[mod].diceType + 8);

		mod = 0;
		printf(" %s: + %d D%d to hit\n\n", toHit[mod].name, toHit[mod].plusDice, toHit[mod].diceType + 6);
	}
}


void createWeaponRNG_TwoHandM(int rarity, int size, Weapon TwoHand[], Damage damage[], ToHit toHit[], Random random[])
{
	int i = 0;
	int modType = 0;
	int mod = 0;

	i = rand() % size;

	if (rarity == 1)
	{
		printf("\n %s, %d d%d damage\n\n", TwoHand[i].name, TwoHand[i].diceTotal, TwoHand[i].diceType);
	}

	else if (rarity == 2)
	{
		modType = rand() % 100;
		if (modType < 60)
		{
			do {
				mod = rand() % 20;
			} while (random[mod].num != 1);
			printf("\n %s, %d d%d damage\n %s: %s\n\n", TwoHand[i].name, TwoHand[i].diceTotal, TwoHand[i].diceType, random[mod].name, random[mod].desrption);
		}
		else if (modType >= 60 && modType < 80)
		{
			do {
				mod = rand() % 10;
			} while (damage[mod].plusDice < 1);
			printf("\n %s, %d d%d damage\n %s: + %d D%d damage\n\n", TwoHand[i].name, TwoHand[i].diceTotal, TwoHand[i].diceType, damage[mod].name, damage[mod].plusDice, damage[mod].diceType);
		}
		else if (modType >= 80)
		{
			mod = 0;
			printf("\n %s, %d d%d damage\n %s: + %d D%d to hit\n\n", TwoHand[i].name, TwoHand[i].diceTotal, TwoHand[i].diceType, toHit[mod].name, toHit[mod].plusDice, toHit[mod].diceType);
		}
	}

	else if (rarity == 3)
	{
		do {
			mod = rand() % 20;
		} while (random[mod].num != 1);
		printf("\n %s, %d d%d damage\n %s: %s\n", TwoHand[i].name, TwoHand[i].diceTotal, TwoHand[i].diceType, random[mod].name, random[mod].desrption);

		if (modType < 50)
		{
			do {
				mod = rand() % 10;
			} while (damage[mod].plusDice < 1);
			printf(" %s: + %d D%d damage\n\n", damage[mod].name, damage[mod].plusDice + 1, damage[mod].diceType);
		}
		else
		{
			mod = 0;
			printf(" %s: + %d D%d to hit\n\n", toHit[mod].name, toHit[mod].plusDice, toHit[mod].diceType + 2);
		}
	}

	else if (rarity == 4)
	{
		do {
			mod = rand() % 20;
		} while (random[mod].num != 1);
		printf("\n %s, %d d%d damage\n %s: %s\n", TwoHand[i].name, TwoHand[i].diceTotal, TwoHand[i].diceType, random[mod].name, random[mod].desrption);

		do {
			mod = rand() % 10;
		} while (damage[mod].plusDice < 1);
		printf(" %s: + %d D%d damage\n", damage[mod].name, damage[mod].plusDice, damage[mod].diceType + 16);

		mod = 0;
		printf(" %s: + %d D%d to hit\n\n", toHit[mod].name, toHit[mod].plusDice, toHit[mod].diceType + 6);
	}
}



void createWeaponRNG_OneHandR(int rarity, int size, Weapon OneRange[], Damage damage[], ToHit toHit[], Random random[])
{
	int i = 0;
	int modType = 0;
	int mod = 0;

	i = rand() % size;

	if (rarity == 1)
	{
		printf("\n %s, %d d%d damage\n\n", OneRange[i].name, OneRange[i].diceTotal, OneRange[i].diceType);
	}

	else if (rarity == 2)
	{
		modType = rand() % 100;
		if (modType < 60)
		{
			do {
				mod = rand() % 20;
			} while (random[mod].num != 1);
			printf("\n %s, %d d%d damage\n %s: %s\n\n", OneRange[i].name, OneRange[i].diceTotal, OneRange[i].diceType, random[mod].name, random[mod].desrption);
		}
		else if (modType >= 60 && modType < 80)
		{
			do {
				mod = rand() % 10;
			} while (damage[mod].plusDice < 1);
			printf("\n %s, %d d%d damage\n %s: + %d D%d damage\n\n", OneRange[i].name, OneRange[i].diceTotal, OneRange[i].diceType, damage[mod].name, damage[mod].plusDice, damage[mod].diceType);
		}
		else if (modType >= 80)
		{
			mod = 0;
			printf("\n %s, %d d%d damage\n %s: + %d D%d to hit\n\n", OneRange[i].name, OneRange[i].diceTotal, OneRange[i].diceType, toHit[mod].name, toHit[mod].plusDice, toHit[mod].diceType);
		}
	}

	else if (rarity == 3)
	{
		do {
			mod = rand() % 20;
		} while (random[mod].num != 1);
		printf("\n %s, %d d%d damage\n %s: %s\n", OneRange[i].name, OneRange[i].diceTotal, OneRange[i].diceType, random[mod].name, random[mod].desrption);

		if (modType < 50)
		{
			do {
				mod = rand() % 10;
			} while (damage[mod].plusDice < 1);
			printf(" %s: + %d D%d damage\n\n", damage[mod].name, damage[mod].plusDice, damage[mod].diceType + 2);
		}
		else
		{
			mod = 0;
			printf(" %s: + %d D%d to hit\n\n", toHit[mod].name, toHit[mod].plusDice, toHit[mod].diceType + 2);
		}
	}

	else if (rarity == 4)
	{
		do {
			mod = rand() % 20;
		} while (random[mod].num != 1);
		printf("\n %s, %d d%d damage\n %s: %s\n", OneRange[i].name, OneRange[i].diceTotal, OneRange[i].diceType, random[mod].name, random[mod].desrption);

		do {
			mod = rand() % 10;
		} while (damage[mod].plusDice < 1);
		printf(" %s: + %d D%d damage\n", damage[mod].name, damage[mod].plusDice, damage[mod].diceType + 8);

		mod = 0;
		printf(" %s: + %d D%d to hit\n\n", toHit[mod].name, toHit[mod].plusDice, toHit[mod].diceType + 6);
	}
}
void createWeaponRNG_TwoHandR(int rarity, int size, Weapon TwoRange[], Damage damage[], ToHit toHit[], Random random[])
{
	int i = 0;
	int modType = 0;
	int mod = 0;

	i = rand() % size;

	if (rarity == 1)
	{
		printf("\n %s, %d d%d damage\n\n", TwoRange[i].name, TwoRange[i].diceTotal, TwoRange[i].diceType);
	}

	else if (rarity == 2)
	{
		modType = rand() % 100;
		if (modType < 60)
		{
			do {
				mod = rand() % 20;
			} while (random[mod].num != 1);
			printf("\n %s, %d d%d damage\n %s: %s\n\n", TwoRange[i].name, TwoRange[i].diceTotal, TwoRange[i].diceType, random[mod].name, random[mod].desrption);
		}
		else if (modType >= 60 && modType < 80)
		{
			do {
				mod = rand() % 10;
			} while (damage[mod].plusDice < 1);
			printf("\n %s, %d d%d damage\n %s: + %d D%d damage\n\n", TwoRange[i].name, TwoRange[i].diceTotal, TwoRange[i].diceType, damage[mod].name, damage[mod].plusDice, damage[mod].diceType);
		}
		else if (modType >= 80)
		{
			mod = 0;
			printf("\n %s, %d d%d damage\n %s: + %d D%d to hit\n\n", TwoRange[i].name, TwoRange[i].diceTotal, TwoRange[i].diceType, toHit[mod].name, toHit[mod].plusDice, toHit[mod].diceType);
		}
	}

	else if (rarity == 3)
	{
		do {
			mod = rand() % 20;
		} while (random[mod].num != 1);
		printf("\n %s, %d d%d damage\n %s: %s\n", TwoRange[i].name, TwoRange[i].diceTotal, TwoRange[i].diceType, random[mod].name, random[mod].desrption);

		if (modType < 50)
		{
			do {
				mod = rand() % 10;
			} while (damage[mod].plusDice < 1);
			printf(" %s: + %d D%d damage\n\n", damage[mod].name, damage[mod].plusDice + 1, damage[mod].diceType);
		}
		else
		{
			mod = 0;
			printf(" %s: + %d D%d to hit\n\n", toHit[mod].name, toHit[mod].plusDice, toHit[mod].diceType + 2);
		}
	}

	else if (rarity == 4)
	{
		do {
			mod = rand() % 20;
		} while (random[mod].num != 1);
		printf("\n %s, %d d%d damage\n %s: %s\n", TwoRange[i].name, TwoRange[i].diceTotal, TwoRange[i].diceType, random[mod].name, random[mod].desrption);

		do {
			mod = rand() % 10;
		} while (damage[mod].plusDice < 1);
		printf(" %s: + %d D%d damage\n", damage[mod].name, damage[mod].plusDice + 1, damage[mod].diceType + 4);

		mod = 0;
		printf(" %s: + %d D%d to hit\n\n", toHit[mod].name, toHit[mod].plusDice, toHit[mod].diceType + 6);
	}
}


/*if (type = 1)
{
	do {
		i = rand() % 15;
	} while (TwoHand[i].name == NULL);
}
if (type = 2)
{
	do {
		i = rand() % 6;
	} while (OneRange[i].name == NULL);
}
if (type = 3)
{
	do {
		i = rand() % 6;
	} while (TwoHand[i].name == NULL);
}
if (type = 4)
{
	do {
		i = rand() % 20;
	} while (Magic[i].name == NULL);
}*/