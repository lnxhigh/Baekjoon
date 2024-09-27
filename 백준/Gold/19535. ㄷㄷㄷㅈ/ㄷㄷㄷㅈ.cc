#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

int64 D(const vector<vector<int>> &tree, const int N) {
    int64 res = 0;
    for (int i = 0; i < N; i++) {
        for (int j : tree[i]) {
            int64 x = (int64) tree[i].size();
            int64 y = (int64) tree[j].size();
            res += (x - 1) * (y - 1);
        }
    }
    
    return res / 2;
}

int64 G(const vector<vector<int>> &tree, const int N) {
    int64 res = 0;
    for (int i = 0; i < N; i++) {
        int64 k = (int64) tree[i].size();
        res += k * (k-1) * (k-2) / 6;
    }
    
    return res;
}

int main() {
    FastIO
    
    int N; cin >> N;
    vector<vector<int>> tree(N);

    for (int i = 0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int64 d = D(tree, N);
    int64 g = G(tree, N);

    string res = (d > 3*g) ? "D" : (d < 3*g) ? "G" : "DUDUDUNGA";
    cout << res << '\n';
    return 0;
}
