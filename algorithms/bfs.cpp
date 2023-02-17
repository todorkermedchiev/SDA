#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <climits>

#define SEPARATOR -1

using namespace std;

int *bfs(int root, unordered_map<int, unordered_set<int>> &adjacencyList, int verteciesCount) {
    
    int *shortestPaths = new int[verteciesCount];
    for (int i = 0; i < verteciesCount; ++i) {
        shortestPaths[i] = INT_MAX;
    }

    queue<int> q;
    q.push(root);
    q.push(SEPARATOR);
    
    bool *visited = new bool[verteciesCount]{};

    int level = 1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == SEPARATOR) {
            if (q.empty()) {
                break;
            }

            q.push(SEPARATOR);
            ++level;
            continue;
        }

        visited[curr] = true;

        for (int i = 0; i < verteciesCount; ++i) {
            if (adjacencyList[curr].count(i) == 0 && !visited[i]) {
                q.push(i);               
                if (level < shortestPaths[i]) {
                    shortestPaths[i] = level;
                }
            }
        }
    }
    
    delete[] visited;
    return shortestPaths;
}

#define N 1000
#define SEPARATOR -1

using namespace std;

struct Wrapper {
    int num;
    bool isSeparator;
};

vector<vector<int>> adjacencyList;
bool visited[N];

void bfs_pesho(int root) {
    queue<int> q;
    q.push(root);
    q.push(SEPARATOR);

    int level = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == -1) {
            if (q.empty()) {
                break;
            }
            
            ++level;
            q.push(SEPARATOR);
            continue;
        }

        visited[curr] = true;

        for (int neighbour : adjacencyList[curr]) {

            if (!visited[neighbour]) {
                q.push(neighbour);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int queriesCount;
    cin >> queriesCount;

    int verteciesCount, edgesCount;
    int startVertex;
    
    for (int i = 0; i < queriesCount; ++i) {
        cin >> verteciesCount >> edgesCount;

        unordered_map<int, unordered_set<int>> adjacencyList;

        for (int i = 0; i < edgesCount; ++i) {
            int start, end;
            cin >> start >> end;

            adjacencyList[start - 1].insert(start - 1);
            adjacencyList[end - 1].insert(end - 1);
            adjacencyList[start - 1].insert(end - 1);
            adjacencyList[end - 1].insert(start - 1);
        }
        
        cin >> startVertex;

        int *shortestPaths = bfs(startVertex - 1, adjacencyList, verteciesCount);

        for (int i = 0; i < verteciesCount; ++i) {
            if (i == startVertex - 1) {
                continue;
            }
            
            if (shortestPaths[i] != INT_MAX) {
                cout << shortestPaths[i] << ' ';
            }
            else {
                cout << -1 << ' ';
            }
        }
        cout << '\n';

        delete[] shortestPaths;
    }   

    return 0;
}
