#include <bits/stdc++.h>
using namespace std;
using xy = pair<int,int>;

int R, C;
const int MAX = 1 << 7;
const int INF = 1 << 20;
bool maze[MAX][MAX];

int dist[MAX][MAX];
deque<xy> dq;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> C >> R;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            char x;
            cin >> x;
            maze[r][c] = (x == '1');
        }
    }
    
    fill(&dist[0][0], &dist[R-1][C-1] + 1, INF);
    dist[0][0] = 0;
    dq.push_front({0, 0});
    
    while (!dq.empty()) {
        xy cur = dq.front();
        int x = cur.first, y = cur.second;
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

            int weight = maze[nx][ny] ? 1 : 0;
            if (dist[nx][ny] > dist[x][y] + weight) {
                dist[nx][ny] = dist[x][y] + weight;
                
                xy next = { nx, ny };
                if (weight == 0) dq.push_front(next);
                else dq.push_back(next);
            }
        }

    }

    cout << dist[R-1][C-1] << '\n';
    return 0;
}
