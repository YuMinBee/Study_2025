/*
* File Name : greedy.cpp
* The objective of the program : using greedy and find path
* Last Update : 2025. 05. 17
*/

#include <stdio.h>
#include <string.h>

int solution(const char* name) {
    int len = strlen(name);
    int answer = 0;

    for (int i = 0; i < len; i++) {
        char c = name[i];
        int up = c - 'A';
        int down = 'Z' - c + 1;
        answer += (up < down) ? up : down;
    } // Count the number of alphabet changes

 
    int move = len - 1; 

    // Number of seat moves
    for (int i = 0; i < len; i++) {
        int next = i + 1;

        while (next < len && name[next] == 'A') {
            next++;
        }

        int back_move = 2 * i + len - next;
        int forward_move = i + 2 * (len - next);
        int cur_move = (back_move < forward_move) ? back_move : forward_move;

        if (cur_move < move)
            move = cur_move;
    }

    answer += move;
    return answer;
}