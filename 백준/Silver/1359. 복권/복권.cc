#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N, M, K;

int choose(int n, int k) {
    int x = 1;
    for (int i = 0; i < k; i++) {
        x *= n - i;
        x /= i + 1;
    }
    return x;
}

int main() {
    FastIO
    cin >> N >> M >> K;

    double p = 0;
    for (int i = K; i <= M; i++) {
        p += choose(M, i) * choose(N - M, M - i);
    }
    p /= choose(N, M);
    
    cout << setprecision(16);
    cout << p << '\n';
    return 0;
}
