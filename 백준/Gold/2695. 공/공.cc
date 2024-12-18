#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int solve(int B, int M) {
    if (B == 1) return M;
    vector<int> V(B + 1);

    int cnt = 0;
    while (++cnt) {
        int sum = 0;
        int to = min(cnt, B);

        for (int k = 1; k <= to; k++) {
            V[k] = (k != cnt) ? V[k] * cnt / (cnt - k) : 1;
            sum += V[k];
        }

        if (sum >= M) break;
    }

    return cnt;
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int B, M; cin >> B >> M;
        int cnt = solve(B, M);
        cout << cnt << '\n';
    }

    return 0;
}
