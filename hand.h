#ifndef _HAND_
#define _HAND_

#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "config.h"

typedef struct {
	int hand;
} pokerHand;

void analyze_hand(pokerCard *cards);

#endif