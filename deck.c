#include "deck.h"

pokerCard specCard(int suite, int rank, int dealt)
{
	// deep copy
	pokerCard card;
	card.suite = suite;
	card.rank = rank;
	card.dealt = dealt;
	return card;
}

void swapCards(pokerCard *card_a, pokerCard *card_b)
{
	pokerCard tmp;
	tmp = *card_a;
	*card_a = *card_b;
	*card_b = tmp;
}

void copyCard(pokerCard *src_card, pokerCard *dest_card)
{
	dest_card->suite = src_card->suite;
	dest_card->rank = src_card->rank;
	dest_card->dealt = src_card->dealt;
}

void resetDeck(pokerCard *deck)
{
	int i = 0;
	int j = 0;
	for (i=0; i<SUITE; i++)
	{
		for (j=0; j<RANK; j++)
		{
			(deck+i*RANK+j)->suite = i;
			(deck+i*RANK+j)->rank = j;
			(deck+i*RANK+j)->dealt = 0;
		}
	}
}

bool genRandomCards(pokerCard *deck, pokerCard *cards, int requestNum)
{
	if (deck->dealt)
	{
		return false;
	}
	int i = 0;
	int available = CARD_COUNT;
	for (i=0; i<CARD_COUNT; i++)
	{
		if ((deck+i)->dealt)
		{
			available = i+1;
			break;
		}
	}
	if (available<requestNum)
	{	
		return false;
	}
	// generate a random index and copy to cards
	// swap this card with the last card that is not dealt on the deck
	for (i=0; i<requestNum; i++)
	{
		int rnum = ran_int(0, available-1);
		(deck+rnum)->dealt = 1;
		copyCard(deck+rnum, cards+i);
		swapCards(&deck[rnum], &deck[available-1]);
		available--;
	}
	return true;
}

bool genCards(pokerCard *deck, pokerCard * cards, int requestNum)
{
	if (deck->dealt)
	{
		return false;
	}
	int i = 0;
	int available = CARD_COUNT;
	for (i=0; i<CARD_COUNT; i++)
	{
		if ((deck+i)->dealt)
		{
			available = i+1;
			break;
		}
	}
	if (available<requestNum)
	{	
		return false;
	}
	for (i=0; i<requestNum; i++)
	{
		(deck+i)->dealt = 1;
		copyCard(deck+i, cards+i);
		swapCards(&deck[i], &deck[available-1]);
		available--;
	}
	return true;
}

void shuffleCard(pokerCard *deck, int deckSize, int shuffleSize)
{
	// initialize 2 pointers point to the first card of the deck
	pokerCard *pc_l = deck;
	pokerCard *pc_r = deck;
	int i = 0;
	for (i=0; i<shuffleSize; i++)
	{
		// randomly offset 2 pointers on the deck and swap cards being pointed
		swapCards(pc_l+ran_int(0, deckSize-1), pc_r+ran_int(0, deckSize-1));
	}
}