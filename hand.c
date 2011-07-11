#include "hand.h"

extern const string SUITE_STR[SUITE];
extern const string RANK_STR[RANK];
extern const string DEALT_STR[2];
extern const string POKER_HAND[10];

bool royal_flush(pokerCard *cards);
bool straight_flush(pokerCard *cards);
bool four_ofa_kind(pokerCard *cards);
bool full_house(pokerCard *cards);
bool flush(pokerCard *cards);
bool straight(pokerCard *cards);
bool three_ofa_kind(pokerCard *cards);
bool two_pair(pokerCard *cards);
bool one_pair(pokerCard *cards);
bool high_card(pokerCard *cards);

void analyze_hand(pokerCard *cards)
{
	int i = 0;
	for (i=0; i<HAND_MIN; i++)
	{
		printf("%s %s\n", *(SUITE_STR+(cards+i)->suite), *(RANK_STR+(cards+i)->rank));
	}
	bool (*hand_func[HAND_TOTAL])(pokerCard *cards) = { royal_flush,
														straight_flush,
														four_ofa_kind,
														full_house,
														flush,
														straight,
														three_ofa_kind,
														two_pair,
														one_pair,
														high_card };
	for (i=0; i<HAND_TOTAL; i++)
	{
		if (hand_func[i](cards))
		{
			printf("******************\n");
			printf("%s\n", *(POKER_HAND+i));
			break;
		}
	}
}

/*
 * suppose all 5 cards are sorted
 */
bool royal_flush(pokerCard *cards)
{
	int i = 0;
	for (i=1; i<HAND_MIN; i++)
	{
		// if suite is not compatible
		// then not a royal flush
		if ((cards+i)->suite!=cards->suite)
		{
			return false;
		}
		// if rank is not highest or in order
		// then not
		if ((cards+i)->rank!=8+i)
		{
			return false;
		}
	}
	return true;
}

/*
 * straight flush will be checked based on no royal flush found
 */
bool straight_flush(pokerCard *cards)
{
	int i = 0;
	for (i=1; i<HAND_MIN; i++)
	{
		// initialize poker suite and rank
		if ((cards+i)->suite!=cards->suite)
		{
			return false;
		}
		if ((cards+i)->rank!=cards->rank+i)
		{
			return false;
		}
	}
	return true;
}

/*
 * 
 */
bool four_ofa_kind(pokerCard *cards)
{
	int i = 0;
	int hit = 1;
	pokerCard *p = cards;
	for (i=1; i<HAND_MIN; i++)
	{
		if (i==1)
		{
			if ((cards+i)->rank!=p->rank)
			{
				p++;
			}
			else
			{
				hit++;
			}
		}
		else
		{
			if (hit<4)
			{
				if ((cards+i)->rank!=p->rank)
				{
					return false;
				}
				else
				{
					hit++;
				}
			}
			else
			{
				/* remove this */
				// though 5 card of the same rank won't appear in case of 1 deck
				// this is added because i want to make sure in a multiple deck game
				// 5 cards of the same rank won't count as a four of a kind
				if ((cards+i)->rank==p->rank)
				{
					return false;
				}
			}
		}
	}
	if (hit==4)
	{
		return true;
	}
	return false;
}

/*
 *
 */
bool full_house(pokerCard *cards)
{
	int hit_l = 0;
	int hit_r = 0;
	pokerCard *pl = cards;
	pokerCard *pr = cards+HAND_MIN-1;
	hit_l++;
	hit_r++;
	// sample card from 2 far end of the card array
	if ((pl+1)->rank!=pl->rank)
	{
		return false;
	}
	else
	{
		hit_l++;
	}
	// move toward middle of the array
	if ((pr-1)->rank!=pr->rank)
	{
		return false;
	}
	else
	{
		hit_r++;
	}
	// middle card should match either left pair of right pair
	// else it will not be a full house
	if ((pl+2)->rank==pl->rank)
	{
		hit_l++;
	}
	else if ((pl-2)->rank==pr->rank)
	{
		hit_r++;
	}
	else
	{
		return false;
	}
	return true;
}

/*// i want to keep this implementation
bool full_house(pokerCard *cards)
{
	int hit_l = 0;
	int hit_r = 0;
	int rank_l = -1;
	int rank_r = -1;
	hit_l++;
	hit_r++;
	// sample card from 2 far end of the card array
	//
	if ((cards+1)->rank!=rank_l)
	{
		return false;
	}
	else
	{
		hit_l++;
	}
	// move toward middle of the array
	if ((cards+HAND_MIN-2)->rank!=rank_r)
	{
		return false;
	}
	else
	{
		hit_r++;
	}
	// middle card should match either left pair of right pair
	// else it will not be a full house
	if ((cards+2)->rank==rank_l)
	{
		hit_l++;
	}
	else if ((cards+2)->rank==rank_r)
	{
		hit_r++;
	}
	else
	{
		return false;
	}
	return true;
}*/

/*
 * 5 cards of the same suite
 */
bool flush(pokerCard *cards)
{
	int i = 0;
	for (i=1; i<HAND_MIN; i++)
	{
		if ((cards+i)->suite!=cards->suite)
		{
			return false;
		}
	}
	return true;
}

/*
 * 5 cards of sequential rank, note: in holdem ace can be high or low
 */
bool straight(pokerCard *cards)
{
	int i = 0;
	for (i=1; i<HAND_MIN; i++)
	{
		// negating
		// if rank is not incrementing by 1
		if ((cards+i)->rank!=cards->rank+i)
		{
			// in order to satisfy straight noly one possibility exists
			// that is when ace is the last place of 5 cards
			if (i!=HAND_MIN-1)
			{
				return false;
			} 
			if (!(cards->rank==0&&(cards+i)->rank==RANK-1))
			{
				return false;
			}
		}
	}
	return true;
}

/*
 *
 */
bool three_ofa_kind(pokerCard *cards)
{
	int i = 0;
	pokerCard *p = cards;
	int hit = 1;
	for (i=1; i<HAND_MIN; i++)
	{
		if ((cards+i)->rank!=p->rank)
		{
			p++;
			hit = 1;
		}
		else
		{
			hit++;
		}
		if (hit==3)
		{
			break;
		}
		if (i==HAND_MIN-2&&hit<2)
		{
			return false;
		}
	}
	if (hit==3)
	{
		return true;
	}
	return false;
}

/*
 *
 */
bool two_pair(pokerCard *cards)
{
	// set pointer to 1st and 3rd cards
	// and check if rank equals with next card
	pokerCard *p1 = cards;
	pokerCard *p2 = cards+2;
	bool hit1 = false;
	bool hit2 = false;
	int i = 0;
	for (i=1; i<3; i++)
	{
		// if pair is not found, move pointer to the next
		if (!hit1)
		{
			if ((p1+1)->rank!=p1->rank)
			{
				p1++;
			}
			else
			{
				hit1 = true;
			}
		}
		// if hit is alreay found, then 
		if (!hit2)
		{
			if ((p2+1)->rank!=p2->rank)
			{	
				p2++;
			}
			else
			{
				hit2 = true;
			}
		}
	}
	if (hit1&&hit2)
	{
		return true;
	}
	return false;
}

/*
 *
 */
bool one_pair(pokerCard *cards)
{
	pokerCard *p = cards;
	int i = 0;
	int hit = 1;
	for (i=1; i<HAND_MIN; i++)
	{
		if ((cards+i)->rank!=p->rank)
		{	
			p++;
		}
		else
		{
			hit++;
		}
		if (hit==2)
		{
			break;
		}
	}
	if (hit==2)
	{
		return true;
	}
	return false;
}

/*
 *
 */
bool high_card(pokerCard *cards)
{
	pokerCard *p = cards;
	int i = 0;
	for (i=1; i<HAND_MIN; i++)
	{
		if ((cards+i)->rank>p->rank)
		{
			p += i;
		}
	}
	return true;
}