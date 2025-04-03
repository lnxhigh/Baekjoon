#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 4;

int N;
int X[MAX], Y[MAX];
int walk[MAX], hole[MAX];

int f() {
    for (int i = 1; i <= N; i++) {
        int x = i;
        for (int k = 1; k <= N && x; k++) {
            x = walk[hole[x]];
        }
        if (x) return 1;
    }
    return 0;
}

int dfs() {
    int ret = 0, x = 1;
    while (x <= N && hole[x]) x++;
    if (x > N) return f();

    for (int y = x + 1; y <= N; y++) {
        if (!hole[y]) {
            hole[x] = y, hole[y] = x;
            ret += dfs();
            hole[x] = hole[y] = 0;
        }
    }
    
    return ret;
}

int main() {
    FastIO

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
    }

    for (int i = 1; i <= N; i++) {
        int t = 0;
        for (int j = 1; j <= N; j++) {
            if (Y[j] != Y[i] || X[j] <= X[i]) continue;
            if (t == 0 || X[j] < X[t]) t = j;
        }
        walk[i] = t;
    }

    int ans = dfs();
    cout << ans << '\n';
    return 0;
}
