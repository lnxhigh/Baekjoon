#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX_N = 101, MAX_V = 50001;

vector<pair<int,int>> Coin;
short int D[MAX_N][MAX_V];

int dfs(int n, int x) {
    if (D[n][x] != -1) return D[n][x];

    const auto& [value, cnt] = Coin[n];
    if (n == 0) return D[n][x] = (x % value == 0) && (x / value <= cnt);

    for (int i = 0; i <= cnt; i++) {
        int y = x - value * i;
        if (y < 0) break;
        if (dfs(n - 1, y)) return D[n][x] = 1;
    }
    
    return D[n][x] = 0;
}

int solve() {
    int N; cin >> N;
    Coin.clear();
    Coin.resize(N);
    memset(D, -1, sizeof(D));

    int V = 0;
    for (auto& [value, cnt] : Coin) {
        cin >> value >> cnt;
        V += value * cnt;
    }

    if (V % 2 != 0) return 0;
    V /= 2;

    return dfs(N - 1, V);
}

int main() {
    FastIO
    int T = 3;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}
