#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int studentsCount;
    int competitionsCount;

    cin >> studentsCount >> competitionsCount;

    int* weight = new int[studentsCount];

    for (int i = 0; i < studentsCount; ++i) {
        cin >> weight[i];
    }

    sort(weight, weight + studentsCount);

    int min, max;
    for (int i = 0; i < competitionsCount; ++i) {
        cin >> min >> max;
        if (min > max) {
            cout << 0 << '\n';
            continue;
        }
        
        int minIndex = lower_bound(weight, weight + studentsCount, min) - weight;

        int maxIndex = upper_bound(weight, weight + studentsCount, max) - weight;
        cout << maxIndex - minIndex<< '\n';
    }

    delete[] weight;

    return 0;
}