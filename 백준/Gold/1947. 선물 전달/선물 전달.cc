#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
const int MAX = 1 << 20;
const ll MOD = 1000000000LL;
ll D[MAX];

int main() {
    cin >> N;
    D[0] = 1; D[1] = 0;
    for (ll i = 2; i <= N; i++) {
        D[i] = (i - 1) * (D[i-1] + D[i-2]) % MOD;
    }
    cout << D[N] << '\n';
    return 0;
}
