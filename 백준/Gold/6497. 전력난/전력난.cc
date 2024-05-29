#include <bits/stdc++.h>
#define V_MAX 200000
using namespace std;

typedef struct Edge {
    pair<int,int> p;
    int cost;
} Edge;

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

    while (true) {
        int V, E;
        cin >> V >> E;
        if (V == 0 && E == 0) break;

        for (int i = 0; i < V; i++)     parent[i] = i;
        for (int i = V; i < V_MAX; i++) parent[i] = 0;
        edges.clear();
        
        for (int i = 0; i < E; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            pair<int,int> p = { x, y };
            edges.push_back({ p, z });
        }

        sort(edges.begin(), edges.end(), [] (Edge &left, Edge &right) {
            return left.cost < right.cost;
        });

        int total = 0;
        int save = 0;
        for (Edge edge : edges) {
            total += edge.cost;
            bool res = merge(edge.p.first, edge.p.second);
            if (res) save += edge.cost;
        }

        int answer = total - save;
        cout << answer << '\n';
    }

    return 0;
}
