#include <iostream>
#include <vector>
#include <queue>

#define N 1000
#define SEPARATOR -1

using namespace std;

struct Wrapper {
    int num;
    bool isSeparator;
};

vector<vector<int>> adjacencyList;
bool visited[N];

void bfs(int root) {
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


    return 0;
}