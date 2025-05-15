#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100'005;

int s, f, m;

bool p[MAX];
int cnt[MAX];
vector<int> factors[MAX];


int main() {
    FastIO
    cin >> s >> f >> m;

    // Sieve

    int n = m + 1;
    fill(p, p + n, true);
    p[0] = p[1] = false;
    
    for (long long i = 0; i < n; i++) {
        if (!p[i]) continue;
        factors[i].emplace_back(i);
        
        for (long long j = i * i; j < n; j += i) {
            p[j] = false;
            factors[j].emplace_back(i);
        }
    }

    // Solve

    for (int i = 0; i <= m; i++) {
        if (!p[i]) continue;

        for (int x = s + f; x; x /= i) cnt[i] += x / i;
        for (int x = s; x; x /= i) cnt[i] -= x / i;
        for (int x = f; x; x /= i) cnt[i] -= x / i;
    }

    int ans = 1;

    for (int i = 2; i <= m; i++) {
        bool chk = true;
        int other = i;
        
        for (int x : factors[i]) {
            int t = 0, k = i;
            while (k % x == 0) t++, k /= x;
            while (other % x == 0) other /= x;

            if (cnt[x] < t) chk = false;
        }

        if (other > 1) {
            if (other > m || cnt[other] < 1) {
                chk = false;
            }
        }

        if (chk) ans = i;
    }

    cout << ans << '\n';
    return 0;
}
