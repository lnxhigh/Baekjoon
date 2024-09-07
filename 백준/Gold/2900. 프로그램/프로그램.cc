#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll N, K, Q;
const ll MAX = 1000001;

ll seq[MAX], cumsum[MAX];
ll counts[MAX];

int main() {
    FastIO
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int X; cin >> X;
        counts[X]++;
    }

    for (int i = 1; i < N; i++) {
        if (counts[i] == 0) continue;
        for (int j = 0; j < N; j += i) {
            seq[j] += counts[i];
        }
    }

    for (int i = 0; i < N; i++) {
        cumsum[i+1] = cumsum[i] + seq[i];
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R; cin >> L >> R;
        ll res = cumsum[++R] - cumsum[L];
        cout << res << '\n';
    }

    return 0;
}
