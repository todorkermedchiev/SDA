#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

int main() {
    unordered_map<int, set<int>> indexes;
    queue<int> q;

    int N, M;
    cin >> N >> M;

    int num;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        indexes[num].insert(i);
        q.push(num);
    }

    int counter = 0;
    for (int index = 0; !q.empty(); ++index, q.pop()) {
        int i = q.front();
        int j = i * M;
        int k = j * M;

        if (!indexes[j].empty() && !indexes[k].empty()) {
            for (auto jIt = indexes[j].begin(); jIt != indexes[j].end(); jIt++) {
                if (*jIt > index) {
                    for (auto kIt = indexes[k].begin(); kIt != indexes[k].end(); kIt++) {
                        if (*kIt > *jIt) {
                            ++counter;
                        }
                    }
                }
            }
        }
    }

    cout << counter;

    return 0;
}