#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

bool check(int64 n, int64 k, int64 value) {
    k = min(k, n - k);
    int64 x = 1;
    for (int64 i = 0; i < k; i++) {
        x *= n - i;
        x /= i + 1;
        if (x >= value) return true;
    }
    
    return x >= value;
}

int64 choose(int64 n, int64 k) {
    k = min(k, n - k);
    int64 x = 1;
    for (int64 i = 0; i < k; i++) {
        x *= n - i;
        x /= i + 1;
    }
    
    return x;
}

string f(int64 N, int64 M, int64 K) {
    if (N == 0 || M == 0) {
        char suffix = N ? 'a' : 'z';
        return string(N + M, suffix);
    }

    bool flag = check(N + M - 1, M , K);
    string prefix = flag ? "a" : "z";
    K -= !flag ? choose(N + M - 1, M) : 0;
    flag ? --N : --M;

    return prefix + f(N, M, K);
}

int main() {
    int64 N, M, K;
    cin >> N >> M >> K;
    bool valid = check(N + M, N, K);
    string res = valid ? f(N, M, K) : "-1";
    cout << res << '\n';
    return 0;
}
