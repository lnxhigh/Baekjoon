#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;
const int INF = 1 << 30;

int N, M;
int C[MAX];
int D[MAX][201][11];

int f(int prv, int cur) {
    int diff = cur - prv;
    if (diff >= 0) return 0;
    return diff * diff;
}

int dfs(int n, int m, int cur) {
    if (m < 0) return INF;
    if (D[n][m][cur] != -1) return D[n][m][cur];
    else if (n == 0) return D[n][m][cur] = 0;
    
    int ret = INF;
    for (int prv = C[n - 1]; prv <= 10; prv++) {
        int diff = prv - C[n - 1];
        ret = min(ret, dfs(n - 1, m - diff, prv) + f(prv, cur));
    }

    return D[n][m][cur] = ret;
}

int main() {
    FastIO
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    memset(D, -1, sizeof(D));
    int ans = INF;
    for (int cur = C[N - 1]; cur <= 10; cur++) {
        int diff = cur - C[N - 1];
        ans = min(ans, dfs(N - 1, M - diff, cur));
    }
    cout << ans << '\n';
    return 0;
}
