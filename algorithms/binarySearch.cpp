#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

bool checkTime(ull time, ull target, vector<int> &times) {
    ull count = 0;
    for (ull i = 0; i < times.size(); ++i) {
        count += time / times[i];
    }
    
    return count >= target;
}

ull binarySearch(ull target, vector<int> &times) {
    ull left = 0;
    ull right = left - 1;
    
    ull ans = 0;
    while (left <= right) {
        ull mid = (left + right) / 2;
        
        if (checkTime(mid, target, times)) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return ans;
}

int main() {
    ull targetCount, cooksCount;
    cin >> targetCount >> cooksCount;
    
    vector<int> times(cooksCount);
    for (ull i = 0; i < cooksCount; ++i) {
        cin >> times[i];
    }
    
    cout << binarySearch(targetCount, times);
    
    return 0;
}
