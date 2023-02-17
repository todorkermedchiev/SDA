#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findRoot(int root, vector<int> &parents) {
    if (parents[root] == root) {
        return root;
    }

    parents[root] = findRoot(parents[root], parents);
    return parents[root];
}

void _union(int first, int second, vector<int> &parents) {
    int rootFirst = findRoot(first, parents);
    int rootSecond = findRoot(second, parents);

    if (rootFirst == rootSecond) {
        return;
    }

    parents[rootSecond] = rootFirst;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int townsCount, roadsCount;
    cin >> townsCount >> roadsCount;

    vector<int> parents(townsCount + 1);
    for (int i = 0; i < townsCount; ++i) {
        parents[i] = i;
    }

    for (int i = 0; i < roadsCount; ++i) {
        int first, second;
        cin >> first >> second;

        _union(first, second, parents);
    }

    int queriesCount;
    cin >> queriesCount;

    for (int i = 0; i < queriesCount; ++i) {
        int type, start, end;
        cin >> type >> start >> end;

        if (type == 1) {
            cout << (findRoot(start, parents) == findRoot(end, parents));
        }
        else if (type == 2) {
            _union(start, end, parents);
        }
    }


    return 0;
}