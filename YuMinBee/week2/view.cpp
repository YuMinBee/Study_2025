/*
* File Name : view.cpp
* The objective of the program : checking of the number of households with access to view
* Developer of the program : YuMin Byeon
* Last Update : 2025. 05. 25
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max4(int a, int b, int c, int d);

int main() {

    for (int T = 1; T <= 10; T++) {
        int size;
        scanf("%d", &size);

        int array[1000];
        for (int i = 0; i < size; i++) {
            scanf("%d", &array[i]);
        }

        int count = 0;
        for (int i = 2; i < size - 2; i++) {
            int max = max4(array[i - 2], array[i - 1], array[i + 1], array[i + 2]);
            if (array[i] > max)
                count += array[i] - max;
        }

        printf("#%d %d\n", T, count);
    }

	return 0;
}

int max4(int a, int b, int c, int d) {
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;
	return max;
}