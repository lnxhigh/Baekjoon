#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int V, E;
bool D[MAX][MAX];

int P[MAX];
vector<tuple<int,int,int>> edges;

int X, K;
vector<pair<int,int>> result;

int find(int x) {
    if (x == P[x]) return x;
    return P[x] = find(P[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    x > y ? P[x] = y : P[y] = x;
    return true;
}

int main() {
    FastIO
    cin >> V >> E;
    
    while (E--) {
        int x, y; cin >> x >> y;
        D[x][y] = D[y][x] = true;
    }
    for (int i = 1; i <= V; i++) {
        D[1][i] = D[i][1] = true;
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            int w; cin >> w;
            if (D[i][j]) w = 0;
            if (i < j) edges.push_back({ w, i, j });
        }
    }

    iota(P, P + V + 1, 0);
    sort(edges.begin(), edges.end());

    for (auto [w, x, y] : edges) {
        if (x == 1 || y == 1) continue;

        bool isMerged = merge(x, y);
        if (!isMerged || D[x][y]) continue;

        X += w, K++;
        result.push_back({ x, y });
    }

    cout << X << ' ' << K << '\n';
    for (auto [x, y] : result) cout << x << ' ' << y << '\n';

    return 0;
}
