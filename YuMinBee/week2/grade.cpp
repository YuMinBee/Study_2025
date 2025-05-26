/*
* File Name : grade.cpp
* The objective of the program : a grade-scoring program
* Developer of the program : YuMin Byeon
* Last Update : 2025. 05. 26
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define NUM_MAX 100

int main() {

	const char* grades[10] = {
	"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"
	};

	int T;
	scanf("%d", &T);

	while (T > 0) {
		int N, K;
		scanf("%d %d", &N, &K);

		int scores[NUM_MAX];
		int target_score;
		for (int i = 0; i < N; i++)
		{
			int mid, final, hw;
			scanf("%d %d %d", &mid, &final, &hw);
			scores[i] = mid * 0.35 + final * 0.45 + hw * 0.2;
			if (i + 1 == K)
			{
				target_score = scores[i];
			}
		}

		qsort(scores, N, sizeof(int), cmp);
		int rank = 0;
		for (int i = 0; i < N; i++) {
			if (scores[i] == target_score) {
				rank = i;
				break;
			}
		}

		int grade_index = rank / (N / 10);
		printf("%s\n", grades[grade_index]);

		/*int count_higher = 0;
		for (int i = 0; i < N; i++) {
			if (scores[i] > target_score) {
				count_higher++;
			}
		}

		int group_size = N / 10;
		int grade_index = count_higher / group_size;
		printf("%s\n", grades[grade_index]);*/
	}

	return 0;
}

int cmp(const void* a, const void* b) {
	return (*(int*)b - *(int*)a);
}