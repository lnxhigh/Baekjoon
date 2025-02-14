#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int N;
int A[MAX];
int D[MAX][MAX][10]; //

int dfs(int n, int i, int k) {
    if (k < 0) return i;
    else if (D[n][i][k]) return D[n][i][k];

    int cnt = 1 << k;
    int rem = n - cnt;

    if (i <= rem) return D[n][i][k] = i + cnt;
    return dfs(cnt, i - rem, k - 1);
}

bool check(int first, int second) {
    for (int i = 1; i <= N; i++) {
        int x = dfs(N, i, first);
        int y = dfs(N, x, second);
        if (i != A[y]) return false;
    }

    return true;
}

pair<int,int> solve() {
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            if ((1 << i) >= N || (1 << j) >= N) continue;
            if (check(i, j)) return { i, j };
        }
    }
    return { 0, 0 };
}

int main() {
    FastIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    auto [x, y] = solve();
    cout << x << ' ' << y << '\n';
    return 0;
}
