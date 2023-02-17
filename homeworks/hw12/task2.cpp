#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Road {
    int index;
    int from;
    int to;
    int effort;
    int profit;
};

struct RoadsByEffortComparator {
    bool operator()(const Road &first, const Road &second) const {
        if (first.effort == second.effort) {
            return first.effort * first.profit < second.effort * second.profit;
        }
        return first.effort < second.effort;
    }
} comparator;

int findRoot(int root, vector<int> &parent) {
    if (parent[root] == root) {
        return root;
    }

    parent[root] = findRoot(parent[root], parent);
    return parent[root];
}

void _union(int first, int second, vector<int> &parent) {
    int rootFirst = findRoot(first, parent);
    int rootSecond = findRoot(second, parent);

    if (rootFirst == rootSecond) {
        return;
    }

    parent[rootSecond] = rootFirst;
}

void kruskal(vector<Road> &roads, vector<int> &result, int townsCount, vector<int> &parent) {
    sort(roads.begin(), roads.end(), comparator);

    int componentsCount = townsCount;

    for (Road &road : roads) {
        if (componentsCount == 1) {
            return;
        }

        int root1 = findRoot(road.from, parent);
        int root2 = findRoot(road.to, parent);

        if (root1 != root2) {
            _union(root1, root2, parent);

            result.push_back(road.index);

            --componentsCount;
        }
    }

    if (componentsCount != 1) {
        cout << "Graph is not connected";
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int townsCount, roadsCount;
    cin >> townsCount >> roadsCount;

    vector<int> parent(townsCount + 1);
    for (int i = 0; i < townsCount; ++i) {
        parent[i] = i;
    }

    vector<Road> roads;
    vector<int> result;

    for (int i = 0; i < roadsCount; ++i) {
        int start, end, effort, profit;
        cin >> start >> end >> effort >> profit;

        roads.push_back({i + 1, start, end, effort, profit});
    }

    kruskal(roads, result, townsCount, parent);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << '\n';
    }
    
    return 0;
}