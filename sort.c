#include "sort.h"

void merge_sort_int(int *arr, int *temp, int left, int right, int asec);

void merge_int(int *arr, int *temp, int left, int mid, int right, int asec);

void sort_int(int *arr, int size, int asec)
{
	int *temp = malloc(sizeof(int)*size);
	merge_sort_int(arr, temp, 0, size-1, asec);
	// remeber to free buffer array
	free(temp);
}

void merge_sort_int(int *arr, int *temp, int left, int right, int asec)
{
	int mid = 0;
	if (right>left)
	{
		mid = (right+left)/2;
		merge_sort_int(arr, temp, left, mid, asec);
		merge_sort_int(arr, temp, mid+1, right, asec);
		merge_int(arr, temp, left, mid, right, asec);
	}
}

// this implementation is not fully finish on ordering
/*void merge_int(int *arr, int *temp, int left, int mid, int right, int asec)
{
	int i = 0;
	int j = mid+1;
	int k = left;
	// copy both halves of a to auxiliary array b
	for (i=left; i<=right; i++)
	{
		*(temp+i) = *(arr+i);
	}
	i = left;
	// copy back next-greatest element at each time
	while (i<=mid&&j<=right)
	{
		int ordering = 0;
		if (asec==0)
		{
			if (*(temp+i)>=*(temp+j))
			{
				ordering = 1;
			}
		}
		else if (asec==1)
		{
			if (*(temp+i)<=*(temp+j))
			{
				ordering = 1;
			}
		}
		if (ordering)
		{
			*(arr+k++) = *(temp+i++);
		}
		else
		{
			*(arr+k++) = *(temp+j++);
		}
	}
	// copy back remaining elements of first half (if any)
	while (i<=mid)
	{
		*(arr+k++) = *(temp+i++);
	}
}*/

// efficient variant of merge function
void merge_int(int *arr, int *temp, int left, int mid, int right, int asec)
{
	int i = 0;
	int j = left;
	int k = left;
	while (j<=mid)
	{
		*(temp+i++) = *(arr+j++);
	}
	i = 0;
	while (k<j&&j<=right)
	{
		int ordering = 0;
		if (asec==0)
		{
			if (*(temp+i)>=*(arr+j))
			{
				ordering = 1;
			}
		}
		else if (asec==1)
		{
			if (*(temp+i)<=*(arr+j))
			{
				ordering = 1;
			}
		}
		if (ordering)
		{
			*(arr+k++) = *(temp+i++);
		}
		else
		{
			*(arr+k++) = *(arr+j++);
		}
	}
	while (k<j)
	{
		*(arr+k++) = *(temp+i++);
	}
}

void merge_sort_card(pokerCard *arr, pokerCard *temp,
					 int left , int right, int comparator, int asec);

void merge_card(pokerCard *arr, pokerCard *temp,
				int left, int mid, int right, int comparator, int asec);

void sort_card(pokerCard * arr, int size, int comparator, int asec)
{
	pokerCard *temp = malloc(sizeof(pokerCard)*size);
	merge_sort_card(arr, temp, 0, size-1, comparator, asec);
	// remeber to free buffer array
	free(temp);
}

void merge_sort_card(pokerCard *arr, pokerCard *temp,
					 int left , int right, int comparator, int asec)
{
	int mid = 0;
	if (right>left)
	{
		mid = (right+left)/2;
		merge_sort_card(arr, temp, left, mid, comparator, asec);
		merge_sort_card(arr, temp, mid+1, right, comparator, asec);
		merge_card(arr, temp, left, mid, right, comparator, asec);
	}
}

void merge_card(pokerCard *arr, pokerCard *temp,
				int left, int mid, int right, int comparator, int asec)
{
	int i = 0;
	int j = left;
	int k = left;
	while (j<=mid)
	{
		*(temp+i++) = *(arr+j++);
	}
	i = 0;
	while (k<j&&j<=right)
	{
		int ordering = 0;
		if (comparator==0)
		{
			if ((asec==0&&(temp+i)->suite>=(arr+j)->suite)||
				(asec==1&&(temp+i)->suite<=(arr+j)->suite))
			{
				ordering = 1;
			}	
		}
		else if (comparator==1)
		{
			if ((asec==0&&(temp+i)->rank>=(arr+j)->rank)||
				(asec==1&&(temp+i)->rank<=(arr+j)->rank))
			{
				ordering = 1;
			}
		}
		if (ordering)
		{
			*(arr+k++) = *(temp+i++);
		}
		else
		{
			*(arr+k++) = *(arr+j++);
		}
	}
	while (k<j)
	{
		*(arr+k++) = *(temp+i++);
	}
}