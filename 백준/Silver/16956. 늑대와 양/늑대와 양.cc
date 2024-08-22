#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define For(i, N) for (int i = 0; i < N; i++) 
using namespace std;

int R, C;
const int MAX = 1 << 9;
char Farm[MAX][MAX];

int dr[4] = { -1, 0, +1, 0 };
int dc[4] = { 0, -1, 0, +1 };

bool solve() {
    For(r, R) {
        For(c, C) {
            if (Farm[r][c] != 'W') continue;

            For(d, 4) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

                if (Farm[nr][nc] == 'S') return false;
                else if (Farm[nr][nc] == 'W') continue;
                else Farm[nr][nc] = 'D';
            }
        }
    }

    return true;
}

int main() {
    FastIO

    cin >> R >> C;
    For(r, R) For(c, C) cin >> Farm[r][c];

    bool possible = solve();
    cout << possible << '\n';
    
    if (!possible) return 0;
    For(r, R) { For(c, C) { cout << Farm[r][c]; } cout << '\n'; }

    return 0;
}
