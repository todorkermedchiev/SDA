#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

int main() {
    int elementsCount;
    cin >> elementsCount;
    
    unordered_set<int> s;
    queue<int> q;
    
    size_t maxLength = 0;
    int current;
    for (int i = 0; i < elementsCount; ++i) {
        cin >> current;
        if (s.find(current) != s.end()) {
            maxLength = max(maxLength, q.size());
            while (!q.empty() && q.front() != current) {
                s.erase(q.front());
                q.pop();
            }
            s.erase(q.front());
            q.pop();
        }

        s.insert(current);
        q.push(current);
    }

    cout << max(maxLength, q.size());
    
    return 0;
}