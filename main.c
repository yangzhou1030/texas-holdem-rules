#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "deck.h"
#include "hand.h"
#include "sort.h"

extern const string SUITE_STR[SUITE];
extern const string RANK_STR[RANK];
extern const string DEALT_STR[2];
extern const string POKER_HAND[10];

/* METHODS */
/* initialize requirements
 */
void init()
{
	srand(time(NULL));
}

/*
 * fun section
 */
typedef struct animal_tag
{
	void (*talk)();
} animal;

void cat_talk()
{
	printf("meow, meow!\n");
}

void cat_construct(animal *this)
{
	this->talk = cat_talk;
}

/*
 *
 */
int main (int argc, const string  argv[])
{
	init();
	
	int i = 0;
	pokerCard deck[CARD_COUNT];
	resetDeck(deck);
	
	int dealtNum = HAND_MIN;
	
	pokerCard cards[11][dealtNum];
	
	// royal_flush
	cards[0][0] = specCard(1, 8, 0);
	cards[0][0] = specCard(1, 9, 0);
	cards[0][2] = specCard(1, 10, 0);
	cards[0][3] = specCard(1, 11, 0);
	cards[0][4] = specCard(1, 12, 0);
	
	// straight flush
	cards[1][0] = specCard(2, 6, 0);
	cards[1][1] = specCard(2, 7, 0);
	cards[1][2] = specCard(2, 8, 0);
	cards[1][3] = specCard(2, 9, 0);
	cards[1][4] = specCard(2, 10, 0);
	
	// four of a kind
	cards[2][0] = specCard(0, 7, 0);
	cards[2][1] = specCard(1, 7, 0);
	cards[2][2] = specCard(2, 6, 0);
	cards[2][3] = specCard(2, 7, 0);
	cards[2][4] = specCard(3, 7, 0);
	
	// full house
	cards[3][0] = specCard(0, 7, 0);
	cards[3][1] = specCard(1, 7, 0);
	cards[3][2] = specCard(2, 7, 0);
	cards[3][3] = specCard(3, 8, 0);
	cards[3][4] = specCard(1, 8, 0);
	
	// flush
	cards[4][0] = specCard(0, 5, 0);
	cards[4][1] = specCard(0, 7, 0);
	cards[4][2] = specCard(0, 9, 0);
	cards[4][3] = specCard(0, 12, 0);
	cards[4][4] = specCard(0, 3, 0);
	
	// straight
	cards[5][0] = specCard(0, 8, 0);
	cards[5][1] = specCard(1, 9, 0);
	cards[5][2] = specCard(1, 11, 0);
	cards[5][3] = specCard(3, 12, 0);
	cards[5][4] = specCard(2, 10, 0);
	
	// three of a kind
	cards[6][0] = specCard(0, 8, 0);
	cards[6][1] = specCard(1, 9, 0);
	cards[6][2] = specCard(1, 8, 0);
	cards[6][3] = specCard(3, 8, 0);
	cards[6][4] = specCard(2, 11, 0);
	
	// two pair
	cards[7][0] = specCard(0, 8, 0);
	cards[7][1] = specCard(1, 10, 0);
	cards[7][2] = specCard(1, 8, 0);
	cards[7][3] = specCard(3, 10, 0);
	cards[7][4] = specCard(2, 11, 0);
	
	// one pair
	cards[8][0] = specCard(0, 8, 0);
	cards[8][1] = specCard(1, 10, 0);
	cards[8][2] = specCard(1, 9, 0);
	cards[8][3] = specCard(3, 8, 0);
	cards[8][4] = specCard(2, 11, 0);
	
	// high card
	cards[9][0] = specCard(0, 2, 0);
	cards[9][1] = specCard(1, 3, 0);
	cards[9][2] = specCard(1, 8, 0);
	cards[9][3] = specCard(3, 10, 0);
	cards[9][4] = specCard(2, 12, 0);
	
	// randomly generated card
	genRandomCards(deck, cards[10], dealtNum);
	
	int card_num = 10;
	if (cards[card_num]!=0)
	{
		for (i=0; i<dealtNum; i++)
		{
			printf("%s %i %s\n", *(SUITE_STR+cards[card_num][i].suite), cards[card_num][i].rank, *(DEALT_STR+cards[card_num][i].dealt));
		}
		printf("******************\n");
		sort_card(cards[card_num], dealtNum, 1, 1);
		analyze_hand(cards[card_num]);
	}
    return 0;
}