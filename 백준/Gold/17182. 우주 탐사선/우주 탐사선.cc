#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 4;
const int INF = 1 << 30;

int N, K;
int D[MAX][MAX];

void input() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> D[i][j];
        }
    }
}

void Floyd() {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
}

int solve() {
    int ret = INF;

    vector<int> P;
    for (int i = 0; i < N; i++) {
        if (i != K) P.push_back(i);
    }

    do {
        int t = 0;
        int from = K;

        for (int to : P) {
            t += D[from][to];
            from = to;
        }
        ret = min(ret, t);

    } while (next_permutation(P.begin(), P.end()));

    return ret;
}

int main() {
    FastIO
    input();
    Floyd();
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
