/*
* File Name : grade_cpp.cpp
* The objective of the program : a grade-scoring program
* Developer of the program : YuMin Byeon
* Last Update : 2025. 05. 25
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> grades = {
        "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"
    };

    int T;
    cin >> T;
    int case_num = 1;

    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> scores;
        int target_score = 0;

        for (int i = 0; i < N; i++) {
            int mid, final, hw;
            cin >> mid >> final >> hw;
            double total = mid * 0.35 + final * 0.45 + hw * 0.2;
            scores.push_back(total);

            if (i + 1 == K) {
                target_score = total;
            }
        }

        int count_higher = 0;
        for (int i = 0; i < N; i++) {
            if (scores[i] > target_score) {
                count_higher++;
            }
        }

        int group_size = N / 10;
        int grade_index = count_higher / group_size;
        if (grade_index >= 10) grade_index = 9;

        cout << "#" << case_num << " " << grades[grade_index] << '\n';
        case_num++;
    }

    return 0;
}