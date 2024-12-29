#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 500000;
using int64 = long long;

int64 N;
map<int64,int64> A;
int64 D[MAX];
bool P[MAX];

int main() {
    FastIO

    // input
    cin >> N;

    int64 zero = 0;
    for (int64 i = 0; i < N; i++) {
        int64 x; cin >> x;
        if (x == 0) zero++;
        else A[x]++;
    }

    // sieve
    memset(P, true, sizeof(P));
    P[0] = P[1] = false;
    for (int64 i = 0; i < MAX; i++) {
        if (!P[i]) continue;
        for (int64 j = i * i; j < MAX; j += i) {
            P[j] = false;
        }
    }

    // knapsack
    D[0] = 1;
    for (auto [value, cnt] : A) {
        for (int64 x = MAX - 1; x >= value; x--) {
            for (int64 i = 1; i <= cnt; i++) {
                int64 y = x - i * value;
                if (y >= 0) D[x] += D[y];
            }
        }
    }
    
    int64 ans = 0;
    for (int64 i = 0; i < MAX; i++) {
        if (P[i]) ans += D[i];
    }

    ans *= (zero + 1);
    cout << ans << '\n';
    return 0;
}
