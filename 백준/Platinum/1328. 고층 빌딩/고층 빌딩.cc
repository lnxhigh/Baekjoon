#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1e9 + 7;
const int MAX = 1 << 7;

int64 F[MAX];
int64 C[MAX][MAX], P[MAX][MAX];
int64 D[MAX][MAX];

void init() {
    // Factorial
    F[0] = 1;
    for (int64 i = 1; i < MAX; i++) {
       F[i] = (F[i-1] * i) % MOD;
    }

    // Choose
    for (int i = 0; i < MAX; i++) {
        C[i][0] = C[i][i] = 1;
    }

    for (int n = 1; n < MAX; n++) {
        for (int k = 1; k < n; k++) {
            C[n][k] = C[n-1][k-1] + C[n-1][k];
            C[n][k] %= MOD;
        }
    }

    // Permutation
    for (int n = 0; n < MAX; n++) {
        for (int k = 0; k <= n; k++) {
            P[n][k] = (C[n][k] * F[k]) % MOD;
        }
    }
}

int main() {
    int N, L, R;
    cin >> N >> L >> R;
    init();

    D[0][0] = 1;
    for (int n = 1; n <= N; n++) {
        for (int k = 1; k <= N; k++) {
            if (n < k) continue;

            for (int i = 0; i < n; i++) {
                D[n][k] += P[n-1][n-1-i] * D[i][k-1]; 
                D[n][k] %= MOD;
            }
        }
    }

    int64 res = 0;
    for (int i = 0; i < N; i++) {
        int64 cnt = (D[i][L-1] * D[N-1-i][R-1]) % MOD;
        cnt = (cnt * C[N-1][i]) % MOD;
        res = (res + cnt) % MOD;
    }

    cout << res << '\n';
    return 0;
}
