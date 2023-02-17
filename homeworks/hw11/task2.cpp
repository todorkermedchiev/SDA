#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

vector<int> dijkstra(int start, unordered_map<int, vector<pair<int, int>>> adjacencyList, int nodesCount) {

    vector<int> cameFrom(nodesCount);

    vector<int> distances(nodesCount);
    fill(distances.begin(), distances.end(), INT_MAX);
    distances[start] = 0;

    set<pair<int, int>> s; // distance, node
    s.insert({0, start});
    cameFrom[start] = -1;

    while (!s.empty()) {
        int currentNode = s.begin()->second;
        s.erase(s.begin());

        int distanceToStart = distances[currentNode];

        for (auto &currentEdge : adjacencyList[currentNode]) {
            int distanceToEnd = distances[currentEdge.first];

            if (distanceToEnd > distanceToStart + currentEdge.second) {
                s.erase({distanceToEnd, currentEdge.first});
                distances[currentEdge.first] = distanceToStart + currentEdge.second;
                s.insert({distances[currentEdge.first], currentEdge.first});

                cameFrom[currentEdge.first] = currentNode;
            }
        }
    }

    return distances;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int nodesCount, edgesCount, queriesCount;
    cin >> nodesCount >> edgesCount >> queriesCount;

    unordered_map<int, vector<pair<int, int>>> adjacencyList; // start, [(end, distance), ...]

    for (int i = 0; i < edgesCount; ++i) {
        int start, end, distance;
        cin >> start >> end >> distance;

        adjacencyList[start].push_back({end, distance});
    }

    vector<vector<int>> distances(nodesCount); // from node, distances

    for (int i = 0; i < queriesCount; ++i) {
        int start, end;
        cin >> start >> end;

        if (distances[start].empty()) {
            distances[start] = dijkstra(start, adjacencyList, nodesCount);
        }
        
        int result = distances[start][end];
        cout << (result != INT_MAX ? result : -1) << '\n';
    }

    return 0;
}