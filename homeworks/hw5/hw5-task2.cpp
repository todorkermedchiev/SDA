#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arrayLen, subArrayLen;
    cin >> arrayLen >> subArrayLen;

    int *data = new int[arrayLen];
    for (int i = 0; i < arrayLen; ++i) {
        cin >> data[i];
    }

    int currentMin = data[0];
    for (int i = 0; i < subArrayLen; ++i) {
        if (data[i] < currentMin) {
            currentMin = data[i];
        }
    }
    long long sum = currentMin;

    int start;
    int end;
    for (int i = 1; i <= arrayLen - subArrayLen; ++i) {
        start = i;
        end = i + subArrayLen;

        if (data[end - 1] < currentMin) {
            currentMin = data[end - 1];
        }
        else if (data[start - 1] == currentMin) {
            currentMin = data[start];
            for (int j = start; j < end; ++j) {
                if (data[j] < currentMin) {
                    currentMin = data[j];
                }
            }
        }

        sum += currentMin;
    }

    cout << sum;

    delete[] data;
    return 0;
}