#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to;
    int cost;
};

int V, E;
const int V_MAX = 1 << 10;
vector<Edge> edges;
int parent[V_MAX];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;

    if (x > y) parent[x] = y;
    else       parent[y] = x;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < E; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        Edge edge = { from, to, cost };
        edges.push_back(edge);
    }

    sort(edges.begin(), edges.end(), [] (Edge &left, Edge &right) {
        return left.cost < right.cost;
    });

    int res = 0;
    for (int i = 0; i < E; i++) {
        Edge &edge = edges[i];
        bool isMerged = merge(edge.from, edge.to);
        if (isMerged) res += edge.cost;
    }

    cout << res << '\n';

    return 0;
}
