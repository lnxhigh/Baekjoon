#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 2501;

int N;
int A[MAX];
int D[MAX];
int P[MAX][MAX];

int dfs(int n) {
    if (n < 0) return 0;
    if (D[n]) return D[n];

    D[n] = dfs(n - 1) + 1;
    for (int i = 0; i < n; i++) {
        if (!P[i][n]) continue;
        D[n] = min(D[n], dfs(i - 1) + P[i][n]);
    }
    return D[n];
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < N; i++) {
        int x = A[i], cnt = 0;
        for (int j = i + 1; j < N; j++) {
            if (x > A[j]) break;
            x = A[j] - x;
            if (x != A[j]) cnt++;
            if (x == 0) P[i][j] = cnt;
        }
    }

    int ans = dfs(N - 1);
    cout << ans << '\n';
    return 0;
}
