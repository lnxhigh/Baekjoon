#include <bits/stdc++.h>
using namespace std;
const int MOD = 10007;

// D[N][K]: N개의 포카드 묶음 중 K장을 뽑았을 때
// 최소 하나 이상의 포카드를 만드는 경우의 수
int D[13 + 1][52 + 1];

int power(int x, int p) {
    int y = 1;
    while (p) {
        if (p & 1) y = (y * x) % MOD;
        x = (x * x) % MOD;
        p >>= 1;
    }
    return y;
}

int choose(int n, int k) {
    int res = 1, mul = 1;
    k = min(k, n - k);
    for (int i = 0; i < k; i++) {
        res = res * (n - i) % MOD;
        mul = mul * (i + 1) % MOD;
    }

    int inv = power(mul, MOD - 2);
    return res * inv % MOD;
}

int main() {
    D[1][4] = 1;
    for (int i = 2; i <= 13; i++) {
        for (int j = 1; j <= (i << 2); j++) {
            for (int k = 1; k <= (j >> 2); k++) {
                // 포카드를 k개 만든다
                int draw = choose(i, k); 

                // 남은 카드에 대해 포카드를 구성하지 않는다
                int fail = choose((i - k) << 2, j - (k << 2)) - D[i - k][j - (k << 2)];
                fail = (fail + MOD) % MOD;
                
                D[i][j] += draw * fail % MOD;
            }
            D[i][j] %= MOD;
        }
    }

    int N; cin >> N;
    cout << D[13][N] << '\n';
    return 0;
}
