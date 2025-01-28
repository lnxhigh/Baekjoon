#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 10005;

int N, W;
int A[MAX][2];
int D[MAX][3];

int f(int n, int k) {
    if (k <= 1) return (A[n][k] <= 0) ? 0 : 1;
    int cnt = A[n][0] + A[n][1];
    return (cnt <= 0) ? 0 : (cnt <= W) ? 1 : 2;
}

int g(int n, int k) {
    int cnt = A[n - 1][k] + A[n][k];
    return (cnt <= 0) ? 0 : (cnt <= W) ? 1 : 2;
}

int dfs(int n, int k) {
    if (n < 0) return 0;
    else if (D[n][k]) return D[n][k];
    else if (n == 0) return D[n][k] = f(0, k);
    
    if (k <= 1) {
        D[n][k] = dfs(n - 1, 2) + f(n, k);
        D[n][k] = min(D[n][k], dfs(n - 1, 1 - k) + g(n, k));
    }
    else {
        D[n][k] = min(dfs(n, 0) + f(n, 1), dfs(n, 1) + f(n, 0));
        D[n][k] = min(D[n][k], dfs(n - 1, 2) + f(n, 2));
        if (n >= 1) D[n][k] = min(D[n][k], dfs(n - 2, 2) + (g(n, 0) + g(n, 1)));
    }
    
    return D[n][k];
}

int main() {
    FastIO
    int TC; cin >> TC;
    while (TC--) {
        memset(A, 0, sizeof(A));
        memset(D, 0, sizeof(D));

        cin >> N >> W;
        for (int i = 0; i < N; i++) cin >> A[i][0];
        for (int i = 0; i < N; i++) cin >> A[i][1];

        int ans = dfs(N - 1, 2);

        bool first  = (N > 1) && (A[N - 1][0] + A[0][0] <= W);
        bool second = (N > 1) && (A[N - 1][1] + A[0][1] <= W);

        if (first) {
            int l = A[N - 1][0], r = A[0][0];
            A[N - 1][0] = A[0][0] = 0;
            memset(D, 0, sizeof(D));

            ans = min(ans, dfs(N - 1, 2) + 1);
            A[N - 1][0] = l, A[0][0] = r;
        }

        if (second) {
            int l = A[N - 1][1], r = A[0][1];
            A[N - 1][1] = A[0][1] = 0;
            memset(D, 0, sizeof(D));

            ans = min(ans, dfs(N - 1, 2) + 1);
            A[N - 1][1] = l, A[0][1] = r;
        }
        
        if (first && second) {
            A[N - 1][0] = A[0][0] = 0;
            A[N - 1][1] = A[0][1] = 0;
            memset(D, 0, sizeof(D));

            ans = min(ans, dfs(N - 1, 2) + 2);
        }
        
        cout << ans << '\n';

    }

    return 0;
}
