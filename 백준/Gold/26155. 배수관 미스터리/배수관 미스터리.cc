#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX_V = 100001, MAX_E = 300001, MAX_Q = 100001;

// Graph
int V, E;
tuple<double,int,int> D[MAX_E];

// Query
int Q;
pair<double,int> query[MAX_Q];
int sizes[MAX_Q];

// Union-Find
int P[MAX_V];

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

    // Graph
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b; cin >> a >> b;
        double p; cin >> p;
        D[i] = { p, a, b };
    }
    sort(D, D + E);

    // Query
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        double p; cin >> p;
        query[i] = { p, i };
    }
    sort(query, query + Q);

    // Union-Find
    iota(P, P + V, 0);
    int cnt = V;
    int k = E - 1;

    for (int i = Q - 1; i >= 0; i--) {
        auto [th, idx] = query[i];
        while (k >= 0) {
            auto [p, a, b] = D[k];
            if (p < th) break;
            
            bool isMerged = merge(a, b);
            if (isMerged) cnt--;
            k--;
        }

        sizes[idx] = cnt;
    }

    for (int i = 0; i < Q; i++) {
        cout << sizes[i] << '\n';
    }

    return 0;
}
