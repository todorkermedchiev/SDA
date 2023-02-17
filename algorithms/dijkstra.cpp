#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <climits>

using namespace std;

vector<int> dijkstra(int start, unordered_map<int, vector<pair<int, int>>> &edges, vector<int> &intervals,
                     int nodesCount) {

    vector<int> distances(nodesCount);
    fill(distances.begin(), distances.end(), INT_MAX);
    distances[start] = 0;

    set<pair<int, int>> s; // (distanceTo, node)
    s.insert(pair<int, int>(0, start));

    while(!s.empty()) {
        int currNode = s.begin()->second;
        s.erase(s.begin());

        int distanceToStart = distances[currNode];
        int waiting = intervals[currNode] - distanceToStart % intervals[currNode];
        if (waiting == intervals[currNode]) {
            waiting = 0;
        }

        for (auto &currEdge : edges[currNode]) {
            int distanceToEnd = distances[currEdge.first];

            if (distanceToEnd > distanceToStart + currEdge.second + waiting) {
                s.erase(pair<int, int>(distanceToEnd, currEdge.first));
                distances[currEdge.first] = distanceToStart + currEdge.second + waiting;
                s.insert(pair<int, int>(distances[currEdge.first], currEdge.first));
            }
        }
    }

    return distances;
}

int main() {
    int nodesCount, edgesCount;
    int start, end;

    cin >> nodesCount >> edgesCount;
    cin >> start >> end;

    vector<int> intervals;
    for (int i = 0; i < nodesCount; ++i) {
        int input;
        cin >> input;
        intervals.push_back(input);
    }

    // adjacency list
    unordered_map<int, vector<pair<int, int>>> edges; // start, [(end, distance), ...]
    for (int i = 0; i < edgesCount; ++i) {
        int first, second, distance;
        cin >> first >> second >> distance;

        edges[first].push_back({second, distance});
    }
    
    vector<int> distances = dijkstra(start, edges, intervals, nodesCount);
    
    cout << (distances[end] != INT_MAX ? distances[end] : -1);

    return 0;
}




// от упражение:

const int N = 10;

vector<pair<int, int>> edges[N]; // from -> [{distance, to}, ...]
// vector<tuple<int, int, int>> edges[N];

vector<int> dist(N);


void dijkstra_pesho(int start) {
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[start] = 0;

    set<pair<int, int>> s; // [{dist, node}, ...]
    s.insert(pair(0, start));

    while (!s.empty()) {
        int u = s.begin()->second;
        s.erase(s.begin()); // pop

        for (auto &edge : edges[u]) {
            if (dist[edge.second] > dist[u] + edge.first) {
                s.erase(pair(dist[edge.second], edge.second)); // ако го няма не прави нищо
                dist[edge.second] = dist[u] + edge.first;
                s.insert(pair(dist[edge.second], edge.second));
            }
        }
    }

}