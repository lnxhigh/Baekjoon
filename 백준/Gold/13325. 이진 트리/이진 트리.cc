#include <bits/stdc++.h>
using namespace std;
using int64 = unsigned long long;
const int64 MAX = (1 << 21) + 5;

int64 N, K;
int64 W[MAX];
int64 D[MAX], M[MAX];

int64 dfs_sum(int x) {
    if (x == 1) return 0;
    else if (D[x]) return D[x];
    return D[x] = dfs_sum(x >> 1) + W[x];
}

int64 dfs_max(int x) {
    if (x > N / 2) return 0;
    else if (M[x]) return M[x];
    
    int l = x * 2, r = x * 2 + 1;
    return M[x] = max(dfs_max(l) + W[l], dfs_max(r) + W[r]);
}

void dfs_solve(int x, int64 val) {
    if (x > N / 2) return;
    int l = x * 2, r = x * 2 + 1;

    W[l] += val - (dfs_max(l) + W[l]);
    dfs_solve(l, val - W[l]);

    W[r] += val - (dfs_max(r) + W[r]);
    dfs_solve(r, val - W[r]);
}

int main() {
    cin >> K;
    N = (1LL << (K + 1)) - 1;
    for (int i = 2; i <= N; i++) cin >> W[i];

    int64 val = 0;
    for (int i = (N / 2) + 1; i <= N; i++) {
        val = max(val, dfs_sum(i));
    }
    dfs_solve(1, val);

    int64 ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += W[i];
    }

    cout << ans << '\n';
    return 0;
}
