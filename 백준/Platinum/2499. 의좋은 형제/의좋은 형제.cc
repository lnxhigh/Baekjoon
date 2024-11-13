#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int INF = 1 << 20;

int N, X;
int A[21][21];
int S[21][21];
int D[21][21][40001];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            X += A[i][j];
        }
    }
}

void init() {
    memset(D, -1, sizeof(D));

    for (int row = 0; row < N; row++) {
        for (int col = N - 1; col >= 0; col--) {
            S[row][col] = A[row][col];
            if (col + 1 <= N) S[row][col] += S[row][col + 1];
        }
    }
}

int dfs(int x, int y, int amt) {
    if (x < 0 || y >= N) return abs(X - amt - amt);
    int &ret = D[x][y][amt];
    if (ret != -1) return ret;
    ret = INF;

    int sum = 0;
    for (int row = x; row >= -1; row--) {
        ret = min(ret, dfs(row, y + 1, amt + sum));
        if (row >= 0) sum += S[row][y];
    }

    return ret;
}

tuple<int,int,int> track(int x, int y, int amt) {
    if (y >= N) return { x, y, -1 };
    else if (x < 0) return { x, y + 1, amt };

    int sum = 0;
    for (int row = x; row >= -1; row--) {
        if (dfs(x, y, amt) == dfs(row, y + 1, amt + sum)) {
            return { row, y + 1, amt + sum };
        }
        if (row >= 0) sum += S[row][y];
    }

    return { -1, -1, -1 };
}

void solve() {
    int x = N - 1, y = 0, amt = 0;
    cout << dfs(x, y, amt) << '\n';

    while (true) {
        tie(x, y, amt) = track(x, y, amt);
        if (amt == -1) break;
        cout << N - x - 1 << ' ';
    }
    cout << '\n';
}

int main() {
    FastIO
    input();
    init();
    solve();
    return 0;
}
