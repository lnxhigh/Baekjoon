#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100000;

int V, E;
pair<int,int> Edges[MAX << 1];

int P[MAX];
int D[MAX];
vector<int> T;

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

void input() {
    cin >> V >> E;
    T.reserve(V);

    for (int i = 0; i < E; i++) {
        int x, y; cin >> x >> y; --x, --y;
        Edges[i] = { x, y };
    }
}

void solve() {
    // Union-Find
    iota(P, P + V, 0);

    int cnt = V;
    for (int i = 0; i < E; i++) {
        auto [x, y] = Edges[i];
        
        bool isMerged = merge(x, y);
        if (!isMerged) continue;
        
        D[x]++, D[y]++;
        T.push_back(i);
        --cnt;
    }

    // Exception
    if (V <= 2 || cnt >= 3) {
        cout << -1 << '\n';
        return;
    }

    // Find leaf
    int leaf = -1;
    if (cnt == 1) {
        for (int i = 1; i < V; i++) {
            if (D[i] <= 1) leaf = i;
        }
        
        assert(leaf != -1);
        fill(P, P + V, 0);
        P[leaf] = leaf;
    }

    // Measure the size
    int zero = 0, one = 0;
    for (int i = 0; i < V; i++) {
        if (find(i) == 0) zero++;
        else one++;
    }
    
    if (zero == one) {
        cout << -1 << '\n';
        return;
    }

    // 1
    cout << zero << ' ' << one << '\n';

    // 2
    for (int i = 0; i < V; i++) {
        if (find(i) == 0) cout << i + 1 << ' ';
    }
    cout << '\n';

    // 3
    for (int i : T) {
        auto [x, y] = Edges[i];
        if (x == leaf || y == leaf) continue;
        if (find(x) == 0) cout << i + 1 << ' ';
    }
    cout << '\n';

    // 4
    for (int i = 0; i < V; i++) {
        if (find(i) != 0) cout << i + 1 << ' ';
    }
    cout << '\n';

    // 5
    for (int i : T) {
        auto [x, y] = Edges[i];
        if (x == leaf || y == leaf) continue;
        if (find(x) != 0) cout << i + 1 << ' ';
    }
    cout << '\n';

    return;
}

int main() {
    FastIO
    input();
    solve();
    return 0;
}
