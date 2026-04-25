#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

int64 input() {
    string S; cin >> S;
    auto iter = find(S.begin(), S.end(), '.');
    assert(iter != S.end());
    
    auto p = iter - S.begin();
    string integer = S.substr(0, p);
    string decimal = S.substr(p + 1);

    assert((int) decimal.size() == 3);
    int64 x = stoi(integer);
    int64 y = stoi(decimal);

    return (x * 1000LL + y) * 10LL;
}

int64 solve(int64 n) {
    const int64 M = 1000000;
    int64 low = max(0LL, n - 5);
    int64 high = n + 5;

    for (int64 x = 1; x <= M; x++) {
        int64 a = low * x, b = high * x;
        a = (a % M == 0) ? a / M : a / M + 1;
        b = (b % M == 0) ? b / M - 1 : b / M;
        if (a <= b) return x;
    }

    return M;
}

int main() {
    FastIO
    int T; cin >> T;

    while (T--) {
        int n = input();
        int ans = solve(n);
        cout << ans << '\n';
    }

    return 0;
}
