#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct weapon
{
	char name[30];
	int kind; //1 one handed melee, 2 two handed melee, 3 one handed ranged, 4 two handed ranged, 5 magic
	int damageType; //1 is piercing, 2 is slashing, 3 is bludgeon, 4 magic
	int diceTotal; //total damage dice pre-modifier
	int diceType; //type of dice

}Weapon;

typedef struct physical
{
	char name[30];
	int plusDice; //how many more dice are added
	int diceType; //type of dice
	int magicDamage; //0 none, 1 fire, 2 ice, 3 necrotic, (more to come)

}Damage;

typedef struct tohit
{
	char name[30];
	int plusDice;
	int diceType;
}ToHit;

typedef struct magicability
{
	char name[30];
	int dcMod;
	int toHit;
}MagicAbility;

typedef struct magiclogistic
{
	char name[30];
	int spellSlot;
	int readySpell;
}MagicLogistic;

typedef struct random
{
	char name[20];
	char desrption[100];
	int num;
}Random;


void get_input(int* choice, int* lootTier, int* totalItems, int* one_hand, int* two_hand, int* one_range, int* two_range);
void clear_screen(void);
int determineRarity(int lootTier);
void createWeaponRNG_OneHandM(int rarity, int size, Weapon OneHand[], Damage damage[], ToHit toHit[], Random random[]);
void createWeaponRNG_TwoHandM(int rarity, int size, Weapon TwoHand[], Damage damage[], ToHit toHit[], Random random[]);
void createWeaponRNG_OneHandR(int rarity, int size, Weapon OneRange[], Damage damage[], ToHit toHit[], Random random[]);
void createWeaponRNG_TwoHandR(int rarity, int size, Weapon TwoRange[], Damage damage[], ToHit toHit[], Random random[]);
