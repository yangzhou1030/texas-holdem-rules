#ifndef _SORT_
#define _SORT_

#include <stdlib.h>
#include "deck.h"

/*
 * merge sort array integers
 * @params arr - pointer to array of integers
 * @params temp - a pointer to a buffer array
 * @params size - size of input array
 * @params asec - if you want to sort in ascending order, mark 1
 * descending order, mark down 0
 */
void sort_int(int *arr, int size, int asec);

/*
 * merge sort array of poker cards
 * @params arr - pointer to array of poker cards
 * @params size - 
 * @params comparator - factor used to determine order of cars
 * comparator will be 0 if sort on suite, 1 if sort on rank
 * @params asec - if you want to sort in ascending order, mark 1
 * descending order, mark down 0
 */
void sort_card(pokerCard * arr, int size, int comparator, int asec);


#endif