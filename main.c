#include "Header.h"

int main(void)
{
	srand((unsigned int)time(NULL));

	Weapon OneHand[15] = { {"Battle Axe",1,2,1,8}, {"Flail",1,3,1,8}, {"Longsword",1,2,1,8}, {"Morning Star",1,1,1,8}, {"Rapier",1,1,1,8}, {"Scimitar",1,2,1,6}, {"Shortsword",1,1,1,6}, {"Trident",1,1,1,6}, {"War Pick",1,1,1,8}, {"War Hammer",1,3,1,8}, {"Whip",1,2,1,4} };
	Weapon TwoHand[10] = { {"Great Axe",2,2,1,12}, {"Great Sword",2,2,2,6}, {"Glaive",2,2,1,10}, {"Halberd",2,2,1,10}, {"Lance",2,1,1,12}, {"Maul",2,3,2,6}, {"Pike",2,1,1,10} };
	Weapon OneRange[5] = { {"One Handed Crossbow",3,1,1,6} };
	Weapon TwoRange[5] = { {"Light Crossbow",4,1,1,8},{"Shortbow",4,1,1,6},{"Heavy Crossbow",4,1,1,10}, {"Longbow",4,1,1,8} };
	
	/*Weapon Magic[20] = { {"Basic Wand",5,4,0,0}};
	Random magicPerks = {};*/

	Damage damage[10] = { {"Damage increse",1,4,0},{"Fire Damage",1,4,1}, {"Ice Damage",1,4,2}, {"Necrotic Damage",1,4,3} };
	ToHit toHit[1] = { {"Increased To Hit",1,4}};
	Random randomPerks[20] = { {"Divine Protection", "+1 to AC if your character worships a higher being", 1},
		{"Protection", "+5 temporary hit points after a long rest", 1},
		{"Divine Light", "Your weaapon emits a 10 foot radius dim light", 1},
		{"Light Restoration", "+1 to maximum hit dice", 1},
		{"Quick Draw", "+2 to combat initiative rolls", 1},
		{"Lunge", "+5 feet to maximum melee range", 1},
		{"Quick Switch", "Swapping or reloading this weapon only costs a bonus action", 1},
		{"Minor Healing", "Hitting an enemy with this weapon restores 1 hitpoint to your character", 1} };
	

	int lootRarity = 0, choice = 0, lootTier = 0, totalItems = 0, one_hand = 0, two_hand = 0, one_range = 0, two_range = 0;
	int sizeOM = 0, sizeTM = 0, sizeOR = 0, sizeTR = 0, sizeM = 0;

	int rarity = 0, type = 0;

	get_input(&choice, &lootTier, &totalItems, &one_hand, &two_hand, &one_range, &two_range);

	for (int x = 0; x < 20; x++)
	{
		if (OneHand[x].kind == 1)
		{
			sizeOM++;
		}
	}
	for (int x = 0; x < 20; x++)
	{
		if (TwoHand[x].kind == 2)
		{
			sizeTM++;
		}
	}
	for (int x = 0; x < 20; x++)
	{
		if (OneRange[x].kind == 3)
		{
			sizeOR++;
		}
	}
	for (int x = 0; x < 20; x++)
	{
		if (TwoRange[x].kind == 4)
		{
			sizeTR++;
		}
	}
	//for (int x = 0; x < 20; x++)
	//{
	//	if (Magic[x].kind == 1)
	//	{
	//		sizeM++;
	//	}
	//}

	if (choice == 1) //RNG
	{
		for (int i = 0; i < totalItems; i++)
		{
			rarity = determineRarity(lootTier);
			type = rand() % 100;
			
			if (type < 30)
			{
				createWeaponRNG_OneHandM(rarity, sizeOM, OneHand, damage, toHit, randomPerks);
			}
			else if (type >= 30 && type < 60)
			{
				createWeaponRNG_TwoHandM(rarity, sizeTM, TwoHand, damage, toHit, randomPerks);
			}
			else if (type >= 60 && type < 65)
			{
				createWeaponRNG_OneHandR(rarity, sizeOR, OneRange, damage, toHit, randomPerks);
			}
			else if (type >= 65 && type < 80)
			{
				createWeaponRNG_TwoHandR(rarity, sizeTR, TwoRange, damage, toHit, randomPerks);
			}
			else if (type >= 80)
			{
				i--; //Did not know enough about magic items to properly input so im just making sure the correct amount of items generate
			}
		}
	}

	if (choice == 2) //Hand picked
	{
		printf("***One Handed Melee Weapons***\n");
		for (int x = 0; x < one_hand; x++)
		{
			rarity = determineRarity(lootTier);
			createWeaponRNG_OneHandM(rarity, sizeOM, OneHand, damage, toHit, randomPerks);
		}
		printf("\n\n\n\n\n***Two Handed Melee Weapons***\n");
		for (int x = 0; x < two_hand; x++)
		{
			rarity = determineRarity(lootTier);
			createWeaponRNG_TwoHandM(rarity, sizeTM, TwoHand, damage, toHit, randomPerks);
		}
		printf("\n\n\n\n\n***One Handed Range Weapons***\n");
		for (int x = 0; x < one_range; x++)
		{
			rarity = determineRarity(lootTier);
			createWeaponRNG_OneHandR(rarity, sizeOR, OneRange, damage, toHit, randomPerks);
		}
		printf("\n\n\n\n\n***Two Handed Range Weapons***\n");
		for (int x = 0; x < two_range; x++)
		{
			rarity = determineRarity(lootTier);
			createWeaponRNG_TwoHandR(rarity, sizeTR, TwoRange, damage, toHit, randomPerks);
		}
	}


	return 0;
}