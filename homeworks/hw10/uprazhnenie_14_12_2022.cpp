#include <iostream>
#include <queue>

#define SIZE 100

using namespace std;

int matrix[SIZE][SIZE] = {}; // 0 - no path, 1 - path exists
bool visited[SIZE];

// връx - vertice
int connectedComponents[SIZE];

void dfs(int root, int index) {
    connectedComponents[root] = index;

    for (int i = 0; i < SIZE; ++i) {
        if (matrix[root][i] == 1 && !visited[i]) {
            if (i == root) {
                continue;
            }
            visited[i] = true;
            dfs(i, index);
        }
    }
}

int main() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++i) {
            int x, y;
            cin >> x >> y;
            matrix[x][y] = 1;
        }
    }

    int index = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (!visited[i]) {
            dfs(i, index);
            ++index;
        }
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;

        cout << (connectedComponents[x] == connectedComponents[y]) << '\n';
    }

    return 0;
}