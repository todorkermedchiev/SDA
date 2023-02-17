#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int dfs(int root, unordered_map<int, vector<int>> &adjacencyList, bool *visited, int &counter) {
    if (visited[root]) {
        return 0;
    }
    
    visited[root] = true;
    
    int nodesCount = 0;
    for (auto neighbour : adjacencyList[root]) {
        int tmp = dfs(neighbour, adjacencyList, visited, counter);
        if (tmp != 0 && tmp % 2 == 0) {
            ++counter;
        }
        nodesCount += tmp;
    }
    
    return nodesCount + 1;
}

int main() {
    int nodesCount, edjesCount;
    cin >> nodesCount >> edjesCount;
    
    unordered_map<int, vector<int>> adjacencyList;
    
    int start, end;
    for (int i = 0; i < edjesCount; ++i) {
        cin >> start >> end;
        
        adjacencyList[start - 1].push_back(end - 1);
        adjacencyList[end - 1].push_back(start - 1);
    }
    
    bool *visited = new bool[nodesCount]{};
    int counter = 0;
    
    dfs(0, adjacencyList, visited, counter);
    
    cout << counter;
    
    delete[] visited;
    
    return 0;
}
