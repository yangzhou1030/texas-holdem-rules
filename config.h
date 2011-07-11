#ifndef _CONFIG_CONST_
#define _CONFIG_CONST_

#include <stdlib.h>

/* CONSTANTS */
#define SUITE 4
#define RANK 13
#define CARD_COUNT SUITE*RANK
#define HAND_MIN 5
#define HAND_TOTAL 10

typedef char* string;

/*
 * gloable variable declarations
 */
const string SUITE_STR[SUITE];
const string RANK_STR[RANK];
const string DEALT_STR[2];
const string POKER_HAND[10];

typedef enum { false = 0, true = 1 } bool;

/* 
 * generate an integer range of min and max,
 * may reach min, may reach max
 * @params -
 */
int ran_int(int min, int max);

/* swap 2 integers
 */
void swap_int(int *a, int *b);


#endif