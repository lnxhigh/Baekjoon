#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 7;

int R, C, T;
int Xc, Yc;
int K;

int D[MAX][MAX];
int M[MAX][MAX];

int dx[8] = { -1, 0, +1, 0, -1, +1, +1, -1 };
int dy[8] = { 0, -1, 0, +1, -1, -1, +1, +1 };

int main() {
    FastIO
    cin >> R >> C >> T;
    cin >> Xc >> Yc;
    cin >> K;

    queue<tuple<int,int,int>> q;
    memset(D, -1, sizeof(D));

    for (int i = 0; i < K; i++) {
        int Xi, Yi;
        cin >> Xi >> Yi;
        q.push({ Xi, Yi, 0 });
        D[Xi][Yi] = 0;
    }

    while (!q.empty()) {
        auto [x, y, t] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            else if (D[nx][ny] != -1) continue;

            q.push({ nx, ny, t + 1 });
            D[nx][ny] = t + 1;
        }
    }

    q.push({ Xc, Yc, 0 });
    memset(M, -1, sizeof(M));
    M[Xc][Yc] = 0;
    
    while (!q.empty()) {
        auto [x, y, t] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            else if (M[nx][ny] != -1) continue;

            q.push({ nx, ny, t + 1 });
            M[nx][ny] = t + 1;
        }
    }

    auto solve = [] () {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (M[i][j] > T) continue;
                if (D[i][j] == -1 || D[i][j] > T) return true;
            }
        }
        return false;
    };

    string ans = solve() ? "YES" : "NO";
    cout << ans << '\n';
    return 0;
}
