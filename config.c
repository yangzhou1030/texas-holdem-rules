#include "config.h"

const string SUITE_STR[SUITE] = { "Club",
								  "Diamond",
								  "Heart",
								  "Spades" };
const string RANK_STR[RANK] = { "2", "3", "4", "5",
								"6", "7", "8", "9", "10",
								"Jack", "Queen", "King", "Ace"};
const string DEALT_STR[2] = { "Not dealt", "Dealt" };
const string POKER_HAND[10] = { "Royal flush",
								"Straight Flush",
								"Four of a kind (Quads)",
								"Full house (Full boat, boat)",
								"Flush",
								"Straight (Run)",
								"Three of a kind (Trips, Set, Triplets)",
								"Two pair",
								"One Pair",
								"High card"};

int ran_int(int min, int max)
{
	return rand()%(max-min+1)+min;
}

void swap_int(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}