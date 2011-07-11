#ifndef _DECK_
#define _DECK_

#include <stdlib.h>
#include "config.h"

/* DATA STRUCTURES */
/* struct resemble a card
 */
typedef struct {
	int suite;
	int rank;
	// dealt is either 0 or 1
	int dealt;
} pokerCard;

/*
 * generate a card with specified rank, suite and dealt value
 * @params suite, rank, dealt -
 */
pokerCard specCard(int suite, int rank, int dealt);

/*
 * swap 2 cards
 * @params - card_a, card_b
 */
void swapCards(pokerCard *, pokerCard *);

/*
 * make a deep copy from source card to destination card
 * this is a deep copy
 */
void copyCard(pokerCard *, pokerCard *);

/*
 * generate a deck of cards, and all card pieces are set in order after
 * @params deck - points to the first of card sequence
 */
void resetDeck(pokerCard *deck);

/*
 * generate number of cards from a deck, cards care randomly selected
 * @params deck - card source
 * @params cards - card target
 * @params numCards
 * <return 0 if cards on deck less than request number
 */
bool genRandomCards(pokerCard *, pokerCard *, int);

/*
 * generate random number of cards from a deck
 * @params deck - card source
 * @params numCards
 * <return 0 if cards on deck less than request number
 */
bool genCards(pokerCard *, pokerCard *, int);

/*
 * swap 2 cards for each shuffle, 2 cards are randomly selected
 * @params deck - points to the first card on the card
 * @params deckSize - number of card on the deck
 * @params shuffleSize - number of swaps
 */
void shuffleCard(pokerCard *deck, int deckSize, int shuffleSize);


#endif