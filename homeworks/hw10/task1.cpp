#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void dfs(int root, int componentIndex, unordered_map<int, unordered_set<int>> &data,
        unordered_set<int> &visited, unordered_map<int, int> &componentsIndexes) {
    if (visited.find(root) != visited.end()) {
        return;
    }   

    visited.insert(root);
    componentsIndexes[root] = componentIndex;

    for (auto it = data[root].begin(); it != data[root].end(); ++it) {
        dfs(*it, componentIndex, data, visited, componentsIndexes);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int verteciesCount, edgesCount;
    cin >> verteciesCount >> edgesCount;

    unordered_map<int, unordered_set<int>> data;
    unordered_set<int> visited;
    unordered_map<int, int> componentsIndexes;
    
    for (int i = 0; i < edgesCount; ++i) {
        int start, end;
        cin >> start >> end;
        
        data[start].insert(end);
        data[end].insert(start);
    }

    int componentIndex = 0;
    for (int i = 0; i < verteciesCount; ++i) {
        if (visited.find(i) == visited.end()) {
            dfs(i, componentIndex, data, visited, componentsIndexes);
            ++componentIndex;
        }
    }

    int queriesCount;
    cin >> queriesCount;

    for (int i = 0; i < queriesCount; ++i) {
        int start, end;
        cin >> start >> end;

        cout << (componentsIndexes[start] == componentsIndexes[end]) << ' ';
    }

    return 0;
}