#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
#define X first
#define Y second
using namespace std;
using Point = pair<int,int>;
const int MAX = 51;

int R, C;
int Map[MAX][MAX];

pair<int,int> P[MAX][MAX];
int S[MAX][MAX];

int dx[4] = { 0, -1, 0, +1 };
int dy[4] = { -1, 0, +1, 0 };

pair<int,int> find(Point m) {
    auto [x, y] = m;
    if (m == P[x][y]) return m;
    return P[x][y] = find(P[x][y]);
}

bool merge(Point a, Point b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (S[a.X][a.Y] < S[b.X][b.Y]) swap(a, b);

    P[b.X][b.Y] = { a.X, a.Y };
    S[a.X][a.Y] += S[b.X][b.Y];
    return true;
}

int main() {
    FastIO
    cin >> C >> R;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> Map[i][j];

            P[i][j] = { i, j };
            S[i][j] = 1;
        }
    }

    int group = R * C;
    int area = 1;
    int sum = 0;

    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if ((Map[x][y] >> dir & 1) || (Map[nx][ny] >> ((dir+2) % 2) & 1)) continue;

                Point cur = { x, y }, nxt = { nx, ny };
                if (merge(cur, nxt)) group--, area = max(area, S[find(cur).X][find(cur).Y]);
            }
        }
    }

    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                Point cur = { x, y }, nxt = { nx, ny };
                cur = find(cur), nxt = find(nxt);
                if (cur != nxt) sum = max(sum, S[cur.X][cur.Y] + S[nxt.X][nxt.Y]);
            }
        }
    }

    cout << group << '\n';
    cout << area << '\n';
    cout << sum << '\n';

    return 0;
}
