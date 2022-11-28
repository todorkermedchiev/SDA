#include <iostream>
#include <set>

using namespace std;

int findGreaterPowerOfTwo(int number) {
    if (number <= 0) {
        return 0;
    }

    int result = 1;

    while (result < number) {
        result *= 2;
    }

    return result;
}

int main() {
    int count;
    cin >> count;

    int current;
    set<int> s;
    for (int i = 0; i < count; ++i) {
        cin >> current;
        int greater = findGreaterPowerOfTwo(current);
        for (int j = 0; j <= greater; ++j) {
            if ((current | j) == current) {
                s.insert(j);
            }
        }
    }

    cout << s.size();

    return 0;
}