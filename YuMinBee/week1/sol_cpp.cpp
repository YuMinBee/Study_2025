/*
* File Name : sol_cpp.cpp
* The objective of the program : checking people who finished marathon
* Last Update : 2025. 05. 17
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> table;
    for (const string& name : participant)
    {
        table[name]++;
    }
    
    for (const string& name : completion)
    {
        table[name]--;
    }

    for (const auto& entry : table) {
        if (entry.second > 0) {
            return entry.first;
        }
    }

}


