#include <bits/stdc++.h>
using namespace std;

int A[19][19];
bool D[19][19][4];

int dr[4] = { -1, +1, +1, 0 };
int dc[4] = { +1, 0, +1, +1 };

void input() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> A[i][j];
        }
    }
}

tuple<int,int,int> solve() {
    for (int c = 0; c < 19; c++) {
        for (int r = 0; r < 19; r++) {
            if (A[r][c] == 0) continue;
            
            for (int i = 0; i < 4; i++) {
                if (D[r][c][i]) continue;

                int color = A[r][c];
                int cnt = 0;

                for (int step = 0; step < 19; step++) {
                    int nr = r + step * dr[i], nc = c + step * dc[i];
                    if (nr < 0 || nr >= 19 || nc < 0 || nc >= 19) break;
                    if (A[nr][nc] != color) break;

                    D[nr][nc][i] = true;
                    cnt++;
                }

                if (cnt == 5) {
                    return { color, r + 1, c + 1 };
                }
            }
        }
    }

    return { 0, 0, 0 };
}

int main() {
    input();
    auto [x, r, c] = solve();
    cout << x << '\n';
    if (x) cout << r << ' ' << c << '\n';
    return 0;
}
