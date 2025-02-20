#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int N, M;
int A[MAX][MAX];
int D[MAX], P[MAX];

int dfs(int x, bool init) {
    if (x == 1 && !init) return 0;
    else if (D[x]) return D[x];

    for (int i = 1; i <= N; i++) {
        if (!A[x][i]) continue;

        int val = A[x][i] + dfs(i, false);
        if (val > D[x]) D[x] = val, P[x] = i;
    }

    return D[x];
}

int main() {
    FastIO
    cin >> N >> M;
    while (M--) {
        int p, q, r; cin >> p >> q >> r;
        A[p][q] = max(A[p][q], r);
    }

    int ans = dfs(1, true);
    cout << ans << '\n';

    int x = 1;
    bool init = true;
    
    while (init || x != 1) {
        cout << x << ' ';
        x = P[x];
        init = false;
    }
    cout << 1 << '\n';

    return 0;
}
