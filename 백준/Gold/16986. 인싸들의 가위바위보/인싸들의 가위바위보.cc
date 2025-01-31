#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N, K;
int A[10][10];
int D[3][20];

void input() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < 20; i++) {
        cin >> D[1][i];
    }
    for (int i = 0; i < 20; i++) {
        cin >> D[2][i];
    }
}

bool fight(int x, int i, int y, int j) {
    if (A[i][j] != 1) return A[i][j];
    return x > y;
}

bool check() {
    int x = 0, y = 1;
    int S[3] = { 0, 0, 0 };
    int T[3] = { 0, 0, 0 };

    while (T[0] < N) {
        int other = 0;
        for (int i = 0; i < 3; i++) {
            if (i != x && i != y) other = i;
        }

        bool flag = fight(x, D[x][T[x]], y, D[y][T[y]]);
        flag ? S[x]++ : S[y]++;
        T[x]++, T[y]++;
        if (S[0] >= K || S[1] >= K || S[2] >= K) return S[0] >= K;

        x = flag ? x : y;
        y = other;
    }

    return false;
}

bool solve() {
    vector<int> P(N);
    iota(P.begin(), P.end(), 1);

    do {
        for (int i = 0; i < N; i++) D[0][i] = P[i];
        if (check()) return true;
    } while (next_permutation(P.begin(), P.end()));
    
    return false;
}

int main() {
    FastIO
    input();
    bool ans = solve();
    cout << ans << '\n';
    return 0;
}
