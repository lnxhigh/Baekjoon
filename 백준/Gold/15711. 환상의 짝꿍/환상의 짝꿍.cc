#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 2000000;

bool IsPrime[MAX];
vector<int64> P;

void sieve() {
    fill(IsPrime + 2, IsPrime + MAX, true);
    P.clear();
    P.reserve(MAX);

    for (int64 i = 0; i < MAX; i++) {
        if (!IsPrime[i]) continue;
        P.push_back(i);

        for (int64 j = i * i; j < MAX; j += i) {
            IsPrime[j] = false;
        }
    }
}

bool f(int64 x) {
    if (x == 1) return false;
    int64 sq = sqrt(x);
    for (int64 i : P) {
        if (i > sq) break;
        if (x % i == 0) return false;
    }
    return true;
}

bool solve(int64 len) {
    if (len % 2 == 0) return len >= 4;
    return f(len - 2);
}

int main() {
    FastIO
    sieve();

    int64 T; cin >> T;
    while (T--) {
        int64 A, B; cin >> A >> B;
        bool flag = solve(A + B);
        string ans = flag ? "YES" : "NO";
        cout << ans << '\n';
    }
    return 0;
}
