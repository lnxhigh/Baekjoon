#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using int64 = long long;
using namespace std;

int main() {
    FastIO
    int64 N, M; cin >> N >> M;
    vector<int64> D(M);

    int64 x = 0;
    D[x]++;

    for (int i = 0; i < N; i++) {
        int64 k; cin >> k;
        x += k; x %= M;
        D[x]++;
    }

    int64 cnt = 0;
    for (int i = 0; i < M; i++) {
        if (D[i] <= 1) continue;
        cnt += D[i] * (D[i] - 1) / 2;
    }

    cout << cnt << '\n';
    return 0;
}
