#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int tc;
int r, c;
vector<string> arr;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int tx[10][10][4], ty[10][10][4];
int fx[10][10][1024], fy[10][10][1024];

int main() {
    FastIO

    cin >> tc;
    while (tc--) {
        cin >> r >> c;

        arr.clear();
        arr.resize(r);
        for (string& line : arr) cin >> line;

        memset(tx, 0, sizeof(tx));
        memset(ty, 0, sizeof(ty));
        memset(fx, 0, sizeof(fx));
        memset(fy, 0, sizeof(fy));

        // Cache

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (arr[i][j] == 'O') {
                    for (int dir = 0; dir < 4; dir++) {
                        tx[i][j][dir] = i;
                        ty[i][j][dir] = j;
                    }
                }
                else if (arr[i][j] == '.') {
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = i, ny = j;
                        while (arr[nx + dx[dir]][ny + dy[dir]] == '.') nx += dx[dir], ny += dy[dir];
                        if (arr[nx + dx[dir]][ny + dy[dir]] == 'O') nx += dx[dir], ny += dy[dir];
                        
                        tx[i][j][dir] = nx;
                        ty[i][j][dir] = ny;
                    }
                }
            }
        }

        // Cache five moves

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (arr[i][j] == '#') continue;

                for (int m = 0; m < 1024; m++) {
                    int nx = i, ny = j;

                    for (int k = 0; k < 5; k++) {
                        int shift = k * 2;
                        int mask = 0b11 << shift;
                        int dir = (m & mask) >> shift;

                        int ux = tx[nx][ny][dir];
                        int uy = ty[nx][ny][dir];
                        
                        nx = ux, ny = uy;
                    }

                    fx[i][j][m] = nx;
                    fy[i][j][m] = ny;
                }
            }
        }

        // Brute force

        int ans = -1;

        for (int m = 0; m < (1 << 20) && (ans < 0); m++) {
            bool chk = true;
            int lo = m % 1024, hi = m / 1024;

            for (int i = 0; i < r && chk; i++) {
                for (int j = 0; j < c && chk; j++) {
                    if (arr[i][j] == '#') continue;

                    int nx = fx[i][j][lo], ny = fy[i][j][lo];
                    int mx = fx[nx][ny][hi], my = fy[nx][ny][hi];
                    chk &= (arr[mx][my] == 'O');
                }
            }

            if (chk) ans = m; 
        }

        if (ans < 0) {
            cout << "XHAE" << '\n';
        }
        else {
            string moves = "";
            
            for (int i = 0; i < 10; i++) {
                int shift = i * 2;
                int mask = 0b11 << shift;
                int dir = (ans & mask) >> shift;

                char where = "ULDR"[dir];
                moves.push_back(where);
            }

            cout << moves << '\n';
        }
    }

    return 0;
}
