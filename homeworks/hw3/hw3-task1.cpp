#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findCandiesCount(long long target, long long start, long long end, int depth = 1) {
    if (start == end) {
        return depth;
    }

    long long middle1 = (2 * start + end) / 3;
    long long middle2 = (start + 2 * end) / 3;

    if (target <= middle1) {
        return findCandiesCount(target, start, middle1,depth + 1);
    }
    if (target > middle2) {
        return findCandiesCount(target, middle2 + 1, end, depth + 1);
    }
    return depth;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int friendsCount;
    int power;

    cin >> power >> friendsCount;

    long long allFriendsCount = pow(3, power);
    int* candiesCount = new int[friendsCount];
    long long* friendsNumber = new long long[friendsCount];

    for (int i = 0; i < friendsCount; ++i) {
        cin >> friendsNumber[i];
    }
    
    for (int i = 0; i < friendsCount; ++i) {
        candiesCount[i] = findCandiesCount(friendsNumber[i] - 1, 0, allFriendsCount - 1);
    }

    for (int i = 0; i < friendsCount; ++i) {
        cout << candiesCount[i] << '\n';
    }

    delete[] candiesCount;
    delete[] friendsNumber;
    return 0;
}
