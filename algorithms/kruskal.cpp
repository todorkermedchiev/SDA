#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10000

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
};

int n, m;
vector<Edge> edges;

// mst = all connections from i to j with weight w
vector<pair<int, int>> mst[MAX]; // i, j, w

int parent[MAX];

int findRoot(int root) {
    if (parent[root] == root) {
        return root;
    }

    parent[root] = findRoot(parent[root]);
    return parent[root];
    
    // return parent[root] = findRoot(parent[root]);
}

void _union(int u, int v) {
    int root_u = findRoot(u);
    int root_v = findRoot(v);

    if (root_u == root_v) {
        return;
    }

    parent[root_v] = root_u;
}

void init(int u) {
    parent[u] = u;
}

void kruskal() {
    sort(edges.begin(), edges.end());
    
    for (int i = 0; i < n; ++i) {
        init(i);
    }

    int componentsCount = n;

    for (Edge &edge : edges) {
        if (componentsCount == 1) {
            return;
        }

        int root1 = findRoot(edge.from);
        int root2 = findRoot(edge.to);

        if (root1 != root2) {
            _union(root1, root2);

            mst[edge.from].push_back({edge.to, edge.weight});
            mst[edge.to].push_back({edge.from, edge.weight});

            --componentsCount;
        }
    }

    if (componentsCount != 1) {
        cout << "Graph is not connected";
    }
}

int main() {


    return 0;
}
