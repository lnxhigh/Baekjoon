#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAXN = 100001, MAXK = 50001, MAXM = 300001;

int N, K, M;
int C[MAXN];
tuple<int,int,int> E[MAXM];

int P[MAXN];
map<int,int> Map[MAXN];
long long A[MAXK];

int find(int x) {
    if (x == P[x]) return x;
    return P[x] = find(P[x]);
}

int main() {
    FastIO
    cin >> N >> K >> M;
    for (int i = 0; i < N; i++) {
        int X; cin >> X; --X;
        C[i] = X;
    }
    for (int i = 0; i < M; i++) {
        int X, Y, W; cin >> X >> Y >> W;
        --X, --Y;
        E[i] = { W, X, Y };
    }
    sort(E, E + M);

    iota(P, P + N, 0);
    for (int i = 0; i < N; i++) {
        Map[i][C[i]]++;
    }

    for (int i = M - 1; i >= 0; i--) {
        auto [W, X, Y] = E[i];

        X = find(X), Y = find(Y);
        if (X == Y) continue;

        if (Map[X].size() < Map[Y].size()) swap(X, Y);
        
        P[Y] = X;
        for (auto [c, cnt] : Map[Y]) {
            A[c] += (long long) W * Map[X][c] * cnt;
            Map[X][c] += cnt;
        }
    }

    for (int i = 0; i < K; i++) {
        cout << A[i] << '\n';
    }

    return 0;
}
