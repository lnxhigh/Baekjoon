#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 16, INF = 1 << 20;

int N;
int A[MAX][MAX];
int S, P;

int D[1 << MAX];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    string str; cin >> str;
    for (int i = 0; i < (int) str.size(); i++) {
        if (str[i] == 'Y') S |= 1 << i;
    }

    cin >> P;
}

int dfs(int x) {
    if (D[x] != -1) return D[x];
    
    if (x & S != S) return INF;
    else if (x == S) return 0;

    int ret = INF;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && (x >> i & 1) && (x >> j & 1)) {
                ret = min(ret, dfs(x & ~(1 << j)) + A[i][j]);
            } 
        }
    }

    return D[x] = ret;
}

int solve() {
    if (P == 0) return 0;
    else if (S == 0) return -1;

    int ret = INF;
    memset(D, -1, sizeof(D));

    for (int i = 0; i < (1 << N); i++) {
        int cnt = 0;
        for (int k = 0; k < N; k++) {
            if (i >> k & 1) cnt++;
        }

        if (cnt >= P) ret = min(ret, dfs(i));
    }

    return ret;
}

int main() {
    FastIO
    input();
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
