#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 5001;
const int64 MOD = 1e9 + 7;

int64 S[MAX]; // Stirling numbers
int64 B[MAX]; // Bell Number
int   P[MAX]; // DSU

int find(int x) {
    if (P[x] == x) return x;
    return P[x] = find(P[x]);
}

bool merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;

    if (x > y) P[x] = y;
    else       P[y] = x;
    return true;
}

int main() {
    FastIO
    int64 N, M; cin >> N >> M;

    S[1] = B[0] = 1;
    iota(P, P + N + 1, 0);

    for (int64 i = 1; i <= N; i++) {
        for (int64 k = i; k > 0; k--) {
            S[k] = (k * S[k] + S[k-1]) % MOD;
            B[i] = (B[i] + S[k]) % MOD;
        }
    }

    // DSU
    int group = N;

    while (M--) {
        int x, y; cin >> x >> y;
        if (merge(x, y)) group--;
        cout << B[group] << '\n';
    }

    return 0;
}
