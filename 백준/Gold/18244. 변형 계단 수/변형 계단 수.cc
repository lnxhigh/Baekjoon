#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007;

int N;
enum { II, ID, DI, DD };
int64 D[128][10][4];

int64 dfs(int n, int d, int k) {
    if (d < 0 || d >= 10) return 0;
    if (D[n][d][k] != -1) return D[n][d][k];

    if (k == II) return D[n][d][k] = dfs(n - 1, d - 1, DI);
    else if (k == ID) return D[n][d][k] = (dfs(n - 1, d + 1, II) + dfs(n - 1, d + 1, DI)) % MOD;
    else if (k == DI) return D[n][d][k] = (dfs(n - 1, d - 1, DD) + dfs(n - 1, d - 1, ID)) % MOD;
    else if (k == DD) return D[n][d][k] = dfs(n - 1, d + 1, ID);
    return D[n][d][k];
}

int64 solve(int n) {
    if (n == 1) return 10;
    if (n == 2) return 18;

    int64 ans = 0;
    for (int d = 0; d < 10; d++) {
        ans += dfs(n, d, II);
        ans += dfs(n, d, ID);
        ans += dfs(n, d, DI);
        ans += dfs(n, d, DD);
        ans %= MOD;
    }
    return ans;
}

int main() {
    cin >> N;
    memset(D, -1, sizeof(D));

    // 인접한 자릿수는 연속으로 3번 이상 증가하거나 감소할 수 없다
    for (int i = 2; i <= 9; i++) D[3][i][II] = 1;
    for (int i = 0; i <= 8; i++) D[3][i][ID] = 1;
    for (int i = 1; i <= 9; i++) D[3][i][DI] = 1;
    for (int i = 0; i <= 7; i++) D[3][i][DD] = 1;

    cout << solve(N) << '\n';
    return 0;
}
