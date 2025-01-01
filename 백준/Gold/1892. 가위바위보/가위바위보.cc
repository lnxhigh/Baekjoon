#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = unsigned long long;
const int MAX = 44;

int N, K;
int64 C[MAX][MAX];

int64 choose(int n, int k) {
    if (k == 0 || k == n) return 1;
    else if (k > n) return 0;
    
    if (C[n][k]) return C[n][k];
    return C[n][k] = choose(n - 1, k) + choose(n - 1, k - 1);
}

pair<int64,int64> solve(int N, int K) {
    int64 cnt = 0;
    for (int win = 0; win < K; win++) {
        for (int lose = 0; lose < K; lose++) {
            if (win + lose > N) continue;
            cnt += choose(N, win) * choose(N - win, lose);
        }
    }

    int64 all = 1;
    for (int i = 0; i < N; i++) all *= 3;

    cnt = (all - cnt) / 2;
    int64 d = gcd(cnt, all);
    cnt /= d, all /= d;

    return { cnt, all };
}

int main() {
    FastIO
    cin >> N >> K;
    auto [cnt, all] = solve(N, K);
    cout << cnt << ' ' << all << '\n';
    return 0;
}
