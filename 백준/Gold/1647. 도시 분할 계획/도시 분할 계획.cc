#include <iostream>
#include <vector>
#include <algorithm>
#define N_MAX 100000
using namespace std;

struct Edge {
    int from;
    int to;
    int cost;
};

int N, M;
int A, B, C;
vector<Edge> edges;

int parent[N_MAX+1];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
int Max(int x, int y) { return x > y ? x : y ; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        edges.push_back({ A, B, C });
    }

    sort(edges.begin(), edges.end(), [] (Edge A, Edge B) {
        if (A.cost < B.cost) return true;
        else return false;
    });

    int cnt = 0;
    int total = 0;
    int costMax = 0;

    for (int i = 0; i < M; i++) {
        Edge edge = edges[i];
        int x = find(edge.from);
        int y = find(edge.to);

        if (x == y) continue;
        
        if (x < y) parent[y] = x;
        else parent[x] = y;
        cnt++;
        total += edge.cost;
        costMax = Max(costMax, edge.cost);

        if (cnt == N-1) break;
    }
    
    cout << total - costMax;

    return 0;
}