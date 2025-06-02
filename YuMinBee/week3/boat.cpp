/*
* File Name : MyVoca.h
* The objective of the program : Finding the maximum number of people on the lifeboat
* Developer of the program : YuMin Byeon
* Last Update : 2025. 06. 02
*/
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int solution(int people[], int peopleSize, int limit) {
	qsort(people, peopleSize, sizeof(int), compare);
	
	// two pointer
	int left = 0;
	int right = peopleSize - 1;
	int boat = 0;

	while (left <= right)
	{
		if (people[left] + people[right] <= limit)
		{
			left++;
		}

		else
		{
			boat++;
		}
	}

	return boat;
}