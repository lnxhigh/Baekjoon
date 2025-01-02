#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 4;

int R, C, D, E;
bool A[MAX][MAX];

void input() {
    cin >> R >> C >> D;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
        }
    }
}

pair<int,int> attack(int i, bool X[MAX][MAX]) {
    pair<int,int> ret = { -1, -1 };
    int limit = D;

    for (int col = C - 1; col >= 0; col--) {
        for (int row = R - 1; row >= 0; row--) {
            if (!X[row][col]) continue;

            int dist = abs(R - row) + abs(i - col);
            if (dist > limit) continue;
            
            limit = dist;
            ret = { row, col };
        }
    }

    return ret;
}

int shoot(int x, int y, int z, bool X[MAX][MAX]) {
    set<pair<int,int>> s;
    for (int i : { x, y, z }) {
        auto [u, v] = attack(i, X);
        if (u != -1 || v != -1) s.insert({ u, v });
    }

    int cnt = s.size();
    for (const auto& [u, v] : s) X[u][v] = false;
    return cnt;
}

void move(bool X[MAX][MAX]) {
    for (int col = C - 1; col >= 0; col--) {
        for (int row = R - 1; row >= 0; row--) {
            if (!X[row][col]) continue;
            
            X[row][col] = false;
            if (row != R - 1) {
                X[row + 1][col] = true;
            }
        }
    }
}

int play(int x, int y, int z) {
    int cnt = 0;
    bool X[MAX][MAX];
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            X[i][j] = A[i][j];
        }
    }

    for (int t = 0; t < R; t++) {
        cnt += shoot(x, y, z, X);
        move(X);
    }

    return cnt;
}

int solve() {
    int cnt = 0;
    for (int i = 0; i < C; i++) {
        for (int j = i + 1; j < C; j++) {
            for (int k = j + 1; k < C; k++) {
                cnt = max(cnt, play(i, j, k));
            }
        }
    }

    return cnt;
}

int main() {
    FastIO
    input();
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
