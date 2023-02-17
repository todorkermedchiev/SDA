#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int nodesCount, edgesCount;
    cin >> nodesCount >> edgesCount;
    
    vector<vector<pair<int, int>>> adjacencyList(nodesCount); // from -> [{to, distance}, ...]
    for (int i = 0; i < edgesCount; ++i) {
        int from, to, distance;
        cin >> from >> to >> distance;
        
        adjacencyList[from].push_back({to, distance});
        adjacencyList[to].push_back({from, distance});
    }
    
    int length = 0;
    
    int count;
    cin >> count;
    
    int from, to;
    cin >> from;
    for (int i = 0; i < count - 1; ++i) {
        cin >> to;
        
        bool isFound = false;
        for (auto curr : adjacencyList[from]) {
            if (curr.first == to) {
                length += curr.second;
                isFound = true;
                break;
            }
        }
        
        if (!isFound) {
            cout << -1;
            return 0;
        }
        
        from = to;
    }
    
    cout << length;
    
    return 0;
}
