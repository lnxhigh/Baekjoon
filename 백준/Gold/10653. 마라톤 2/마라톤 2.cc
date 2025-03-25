#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 9;

int N, K;
pair<int,int> P[MAX];
int D[MAX][MAX];

int dist(int i, int j) {
    int dx = P[i].first - P[j].first;
    int dy = P[i].second - P[j].second;
    return abs(dx) + abs(dy);
}

int dfs(int n, int k) {
    if (D[n][k] != -1) return D[n][k];
    else if (n == N - 1) return D[n][k] = 0;

    int ret = 1 << 30;
    for (int i = 0; i <= k && n + 1 + i < N; i++) {
        ret = min(ret, dfs(n + 1 + i, k - i) + dist(n, n + 1 + i));
    }
    return D[n][k] = ret;
}

int main() {
    FastIO
    memset(D, -1, sizeof(D));

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        P[i] = { x, y };
    }

    int ans = dfs(0, K);
    cout << ans << '\n';
    return 0;
}
