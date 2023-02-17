#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int root, vector<vector<int>> &adjacencyList, vector<bool> &visited) {
    if (visited[root]) {
        return;
    }
    
    visited[root] = true;
    for (auto current : adjacencyList[root]) {
        dfs(current, adjacencyList, visited);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int queriesCount;
    cin >> queriesCount;
    
    for (int i = 0; i < queriesCount; ++i) {
        int townsCount, roadsCount;
        cin >> townsCount >> roadsCount;
        
        vector<vector<int>> adjacencyList(townsCount);
        for (int j = 0; j < roadsCount; ++j) {
            int from, to;
            cin >> from >> to;
            adjacencyList[from].push_back(to);
            adjacencyList[to].push_back(from);
        }
        
        vector<bool> visited(townsCount);
        for (int j = 0; j < townsCount; ++j) {
            visited[j] = false;
        }
        
        int counter = 0;
        for (int j = 0; j < townsCount; ++j) {
            if (!visited[j]) {
                dfs(j, adjacencyList, visited);
                ++counter;
            }
        }
        
        cout << counter << ' ';
    }
    
    return 0;
}
