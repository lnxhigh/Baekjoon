#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
#define X first
#define Y second
using namespace std;
using Point = pair<int,int>;
const int MAX = 1 << 9;

int R, C;
int Elevation[MAX][MAX];
bool Waypoint[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int total = 0;
int cnt = 0;
int ans = 0;

pair<int,int> P[MAX][MAX];
int S[MAX][MAX];

pair<int,int> find(Point p) {
    auto [x,y] = p;
    if (p == P[x][y]) return p;
    return P[x][y] = find(P[x][y]);
}

bool merge(Point p, Point q) {
    p = find(p), q = find(q);
    if (p == q) return false;

    if (S[p.X][p.Y] < S[q.X][q.Y]) swap(p, q); 
    P[q.X][q.Y] = p;
    S[p.X][p.Y] += S[q.X][q.Y];
    return true;
}

int main() {
    FastIO
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> Elevation[i][j];
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> Waypoint[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            P[i][j] = { i, j };
            S[i][j] = Waypoint[i][j] ? 1 : 0;
            if (Waypoint[i][j]) total++;
        }
    }

    vector<tuple<int,Point,Point>> Edges;
    Edges.reserve(R * C * 4);

    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                int diff = abs(Elevation[x][y] - Elevation[nx][ny]);
                Edges.push_back({ diff, { x, y }, { nx, ny } });
            }
        }
    }
    sort(Edges.begin(), Edges.end());

    for (auto [diff, p1, p2] : Edges) {
        if (cnt >= total) break;

        bool isMerged = merge(p1, p2);
        if (!isMerged) continue;
        
        ans = diff;
        auto [x,y] = find(p1);
        cnt = S[x][y];
    }

    cout << ans << '\n';
    return 0;
}
