/*
* File Name : view_cpp.cpp
* The objective of the program : checking of the number of households with access to view
* Developer of the program : YuMin Byeon
* Last Update : 2025. 05. 25
*/
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    for (int T = 1; T <= 10; T++) {
        int size;
        cin >> size;

        vector<int> array(size);
        for (int i = 0; i < size; i++) {
            cin >> array[i];
        }

        int count = 0;
        for (int i = 2; i < size - 2; i++) {
            int maxVal = max(max(array[i - 2], array[i - 1]), max(array[i + 1], array[i + 2]));

            if (array[i] > maxVal)
                count += array[i] - maxVal;
        }

        cout << "#" << T << " " << count << '\n';
    }

    return 0;
}