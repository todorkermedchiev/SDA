#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <climits>

#define SEPARATOR -1

using namespace std;

int *bfs(int root, bool **matrix, int verteciesCount) {
    
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
            if (!matrix[curr][i] && !visited[i]) {
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int queriesCount;
    cin >> queriesCount;

    int verteciesCount, edgesCount;
    int startVertex;
    
    for (int i = 0; i < queriesCount; ++i) {
        cin >> verteciesCount >> edgesCount;

        bool **matrix = new bool*[verteciesCount];
        for (int i = 0; i < verteciesCount; ++i) {
            matrix[i] = new bool[verteciesCount]{};
        }

        for (int i = 0; i < edgesCount; ++i) {
            int start, end;
            cin >> start >> end;

            matrix[start - 1][end - 1] = true;
            matrix[end - 1][start - 1] = true;
            matrix[start - 1][start - 1] = true;
            matrix[end - 1][end - 1] = true;
        }
        
        cin >> startVertex;

        int *shortestPaths = bfs(startVertex - 1, matrix, verteciesCount);

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

        for (int i = 0; i < verteciesCount; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
        delete[] shortestPaths;
    }   

    return 0;
}