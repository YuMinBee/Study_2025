/*
* File Name : MyVoca.h
* The objective of the program : lottary program
* Developer of the program : YuMin Byeon
* Last Update : 2025. 06. 02
*/

#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int cnt = 0;
	int zero_cnt = 0;
	int zero_to_insert;
	int lottos[6] = { 0 };
	int win_nums[6] = { 0 };
	srand(time(NULL));

	// making win numbers
	for (int i = 0; i < 6; i++)
	{
		int num;
		int duplicate_found;
		// checking duplication
		do {
			num = rand() % 45 + 1; // 1~45
			duplicate_found = 0;
			for (int j = 0; j < i; j++)
			{
				if (win_nums[j] == num)
				{
					duplicate_found = 1;
					break;
				}
			}
		} while (duplicate_found);
		win_nums[i] = num;
	}

	// making my lotto numbers
	for (int i = 0; i < 6; i++)
	{
		int num;
		int duplicate_found;
		// checking duplication
		do {
			num = rand() % 45 + 1;
			duplicate_found = 0;
			for (int j = 0; j < i; j++)
			{
				if (lottos[j] == num)
				{
					duplicate_found = 1;
					break;
				}
			}
		} while (duplicate_found);
		lottos[i] = num;
	}

	// input 0
	int rand_num = rand() % 5 +1;
	for (int i = 0; i < rand_num; ) {
		int idx = rand() % 6;
		if (lottos[idx] != 0) {
			lottos[idx] = 0;
			i++;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		if (lottos[i] == 0)
		{
			zero_cnt++;
		}
	}
	
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (lottos[i] == win_nums[j])
			{
				cnt++;
			}
		}
	}

	int* answer = (int*)calloc(2, sizeof(int));

	// Lotto prize rank calculation
	answer[0] = (cnt + zero_cnt) >= 2 ? 7 - (cnt + zero_cnt) : 6;
	answer[1] = cnt >= 2 ? 7 - cnt : 6;

	printf("the highest rank: %d\n", answer[0]);
	printf("the lowest rank: %d\n", answer[1]);
	free(answer);

	return 0;
}

int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
	int zero_cnt = 0;
	int match_cnt = 0;

	for (int i = 0; i < lottos_len; i++) {
		if (lottos[i] == 0) {
			zero_cnt++;
			continue;
		}
		for (int j = 0; j < win_nums_len; j++) {
			if (lottos[i] == win_nums[j]) {
				match_cnt++;
				break;
			}
		}
	}

	int* answer = (int*)malloc(sizeof(int) * 2);
	answer[0] = (match_cnt + zero_cnt >= 2) ? 7 - (match_cnt + zero_cnt) : 6;
	answer[1] = (match_cnt >= 2) ? 7 - match_cnt : 6;
	return answer;
}