#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N, M;
const int MAX = 1 << 10;
vector<int> P[MAX];

int main() {
    FastIO
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int p1, p2; cin >> p1 >> p2;
        vector<int> v = { min(p1,p2), max(p1,p2) };
        P[i] = v;
    }

    if (M > (N << 1)) {
        M %= N;
        M += N;
    }

    for (int round = 0; round < M; round++) {
        int first = P[0][0];
        P[0].erase(P[0].begin());
        for (int k = 1; k < N; k++) {
            int winner = P[k][1];
            P[k].pop_back();
            P[k-1].push_back(winner);
        }
        P[N-1].push_back(first);

        for (int i = 0; i < N; i++) {
            if (P[i][0] < P[i][1]) continue;
            int winner = P[i][0];
            P[i][0] = P[i][1];
            P[i][1] = winner;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << P[i][0] << ' ' << P[i][1] << '\n';
    }

    return 0;
}
