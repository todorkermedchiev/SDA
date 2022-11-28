#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;


int main() {
    int queriesCount;
    cin >> queriesCount;

    int cookiesCount;
    set<int> s;
    for (int i = 0; i < queriesCount; ++i) {
        cin >> cookiesCount;

        queue<int> q;

        int current;
        int maxCount = 0;
        for (int j = 0; j < cookiesCount; ++j) {
            cin >> current;

            if (s.find(current) != s.end()) {
                maxCount = (s.size() > maxCount ? s.size() : maxCount);
                while (!q.empty() && q.front() != current) {
                    s.erase(s.find(q.front()));
                    q.pop();
                }
                s.erase(s.find(current));
                q.pop();
            }
                
            q.push(current);
            s.insert(current);
        }

        cout << (s.size() > maxCount ? s.size() : maxCount) << '\n';
        s.clear();
    }

    return 0;
}

