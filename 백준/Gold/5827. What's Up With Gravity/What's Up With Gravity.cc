#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 9;

int R, C;
int X, Y;

char A[MAX][MAX];

bool V[MAX][MAX][2];
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'C') {
                X = i, Y = j;
            }
        }
    }
}

pair<int,int> fall(int x, int y, bool gravity) {
    int dir = gravity ? 2 : 0;
    int nx = x + dx[dir], ny = y + dy[dir];
    return { nx, ny };
}

bool isInside(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

int bfs(int x, int y) {
    deque<tuple<pair<int,int>,int,bool>> dq;
    pair<int,int> init = { x, y };
    dq.push_front({ init, 0, true });
    V[x][y][1] = true;

    while (!dq.empty()) {
        auto [p, cost, gravity] = dq.front();
        auto [cx, cy] = p;
        auto [fx, fy] = fall(cx, cy, gravity);
        dq.pop_front();
        if (A[cx][cy] == 'D') return cost;

        // If there is no cell directly underneath Captain Bovidian
        // then she flies out into space and fails her mission.
        if (!isInside(fx, fy)) continue;

        // If the cell directly underneath Captain Bovidian is empty, 
        // then she falls into that cell.
        if (A[fx][fy] != '#') {
            if (!V[fx][fy][gravity]) {
                pair<int,int> nxt = { fx, fy };
                dq.push_front({ nxt, cost, gravity });
                V[fx][fy][gravity] = true;
            }

            continue;
        }

        // Otherwise: 
        // Captain Bovidian may move left or right if the corresponding cell exists and is empty. 
        for (int i : { 1, 3 }) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (!isInside(nx, ny)) continue;
            else if (A[nx][ny] == '#' || V[nx][ny][gravity]) continue;
            pair<int,int> nxt = { nx, ny };
            dq.push_front({ nxt, cost, gravity });
            V[nx][ny][gravity] = true;
        }

        // Or, Captain Bovidian may flip the direction of gravity.
        if (!V[cx][cy][!gravity]) {
            pair<int,int> nxt = { cx, cy };
            dq.push_back({ nxt, cost + 1, !gravity });
            V[cx][cy][!gravity] = true;
        }
    }

    return -1;
}

int main() {
    FastIO
    input();
    int ans = bfs(X, Y);
    cout << ans << '\n';
    return 0;
}
