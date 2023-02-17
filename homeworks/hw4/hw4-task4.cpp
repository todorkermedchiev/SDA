#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    const int MAX_NUMBER = 100001;
    const int INVALID = -1;
    int invalidCount = 0;
    long long position[MAX_NUMBER];
    for (int i = 0; i < MAX_NUMBER; ++i){
        position[i] = INVALID;
    }

    long long maxPackagesCount;
    long long queriesCount;

    vector<int> data;

    cin >> queriesCount >> maxPackagesCount;

    int *values = new int[queriesCount];

    for (long long i = 0; i < queriesCount; ++i) {
        cin >> values[i];
    }

    for (long long i = 0; i < queriesCount; ++i) {
        if (position[values[i]] != INVALID) {
            data[position[values[i]]] = INVALID;
            ++invalidCount;
            data.push_back(values[i]);
            position[values[i]] = data.size() - 1;
            std::cout << "true" << '\n';
        }
        else {
            if (data.size() == maxPackagesCount + invalidCount) {
                long long counter = 0;
                while (data[counter] == INVALID) {
                    ++counter;
                }
                position[data[counter]] = INVALID;
                data[counter] = INVALID;
                ++invalidCount;
            }
            data.push_back(values[i]);
            position[values[i]] = data.size() - 1;
            std::cout << "false" << '\n';
        }
    }

    delete[] values;
    return 0;
}