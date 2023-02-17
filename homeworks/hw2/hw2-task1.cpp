#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int count;
    cin >> count;

    int* numbers = new int[count];
    int* result = new int[count];

    for (int i = 0; i < count; ++i) {
        cin >> numbers[i];
    }

    int counter = 0;
    for (int i = 0; i < count; ++i) {
        if (numbers[i] % 2 == 0) {
            result[counter++] = numbers[i];
        }
    }

    for (int i = 0; i < count; ++i) {
        if (numbers[i] % 2 == 1) {
            result[counter++] = numbers[i];
        }
    }

    for (int i = 0; i < count; ++i) {
        cout << result[i] << '\n';
    }

    delete[] numbers;
    delete[] result;

    return 0;
}