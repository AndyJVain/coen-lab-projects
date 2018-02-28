/*
Andy Vainauskas
May 12, 2016
Thursday 9:15
Project #4

This is the main function for Radix Sorting. It uses the functions from the deque.c file to sort numbers given by the standard input.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "deque.h"

//O(m) - The runtime depends on the max value
int main(void)
{
	int i;
	int temp = 0;
	int max = 0;
	
	DEQUE *list = createDeque();
	DEQUE *bins[10];

	for(i=0; i<10; i++){	//Initializes the individual bins
		bins[i] = createDeque();
	}
	
	printf("Please enter the numbers, and when done, enter a character.\n");	
	
	while(scanf("%d", &temp) > 0){	//Takes numbers from standard input

		if(temp < 0)
			break;
		
		addLast(list, temp);	//Adds the numbers into the list nodes
	
		if(temp > max){	//Saves the max number to use later
			max = temp;
		}
	}
	

	int iterations = (int)ceil((log(max+1) / log(10)));	//Uses the max number to find the largest number of digits
	int number;
	int div = 1;
	int j;

	for(i=0; i<iterations; i++){	//Loops through the number of max digits

		while(numItems(list) != 0){	//Moves the numbers from the list to the correct bin
			number = removeFirst(list);
			addLast(bins[(number/div)%10], number);
		}

		div *= 10;	//Increments the number to divide by

		for(j=0; j<10; j++){	//Moves the numbers from the bins in order back to the list
			while(numItems(bins[j]) != 0){
				number = removeFirst(bins[j]);
				addLast(list, number);
			}
		}
	}

	while(numItems(list) != 0){	//Outputs the list once the numbers are sorted
		printf("%d\n", removeFirst(list));
	}
	
	for(i=0; i<10; i++){	//Deallocates the bins
		destroyDeque(bins[i]);
	}
	
	destroyDeque(list);	//Deallocates the list
}





