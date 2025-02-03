#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 1 << 7;
const ll MOD = 1'000'000'007;

ll N, K;
bool D[MAX][MAX];
ll F[MAX * MAX];

ll f(ll x, ll p) {
    ll y = 1;
    for (ll i = p; i; i >>= 1) {
        if (i & 1) y = y * x % MOD;
        x = x * x % MOD;
    }
    return y;
}

int main() {
    FastIO
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c; cin >> c;
            D[i][j] = (c == '1');
        }
    }

    F[0] = 1;
    for (ll i = 1; i <= 10000; i++) {
        F[i] = F[i - 1] * i % MOD;
    }
    
    vector<int> B;
    B.reserve(2 * N + 2);

    for (int row = 0; row < N; row++) {
        int cnt = 0;
        for (int col = 0; col < N; col++) {
            if (!D[row][col]) cnt++;
        }
        B.push_back(cnt);
    }

    for (int col = 0; col < N; col++) {
        int cnt = 0;
        for (int row = 0; row < N; row++) {
            if (!D[row][col]) cnt++;
        }
        B.push_back(cnt);
    }

    int x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        if (!D[i][i]) x++;
    }
    for (int i = 0; i < N; i++) {
        if (!D[i][N - 1 - i]) y++;
    }
    B.push_back(x), B.push_back(y);

    ll ans = 0;

    int zeros = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!D[i][j]) zeros++;
        }
    }

    for (int cnt : B) {
        if (K < cnt) continue;
        ll num = F[zeros - cnt] * F[K] % MOD;
        ll den = F[zeros] * F[K - cnt] % MOD;
        ll p = num * f(den, MOD - 2) % MOD;
        p = p * F[N * N] % MOD;
        ans = (ans + p) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
