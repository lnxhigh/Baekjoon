#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 101;

int R, C;
string M;

pair<int,int> me;
vector<pair<int,int>> robots;

int D[MAX][MAX];
char P[MAX][MAX];

int dx[10] = { 0, +1, +1, +1, 0, 0, 0, -1, -1, -1 };
int dy[10] = { 0, -1, 0, +1, -1, 0, +1, -1, 0, +1 };

void input() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char x; cin >> x;
            if (x == 'I') me = { i, j };
            else if (x == 'R') robots.push_back({ i, j });
        }
    }

    cin >> M;
}

void solve() {
    int cnt = 0;
    bool caught = false;

    for (char move : M) {
        // Move my robot
        auto& [x, y] = me;
        int dir = (int) (move - '0');

        cnt++;
        x += dx[dir], y += dy[dir];
        if (D[x][y]) caught = true; 

        if (caught) break;

        for (auto& [rx, ry] : robots) {
            // Find the direction to which the distance gets closer
            int dir = 5;
            int minDist = abs(rx - x) + abs(ry - y);

            for (int i = 1; i <= 9; i++) {
                int nx = rx + dx[i], ny = ry + dy[i];
                int dist = abs(nx - x) + abs(ny - y);
                if (dist < minDist) minDist = dist, dir = i;
            }

            // Move the robot
            rx += dx[dir], ry += dy[dir];
            D[rx][ry]++;
            if (x == rx && y == ry) caught = true;
        }
        if (caught) break;

        vector<pair<int,int>> newRobots;
        newRobots.reserve(robots.size());

        for (auto [x, y] : robots) {
            if (D[x][y] == 1) newRobots.push_back({ x, y });
            D[x][y] = 0;
        }
        robots = newRobots;
    }

    if (caught) {
        cout << "kraj " << cnt << '\n';
        return;
    }

    for (int i = 0; i < R; i++) {
        fill(P[i], P[i] + C, '.');
    }

    P[me.first][me.second] = 'I';
    for (auto [x, y] : robots) P[x][y] = 'R';

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << P[i][j];
        }
        cout << '\n';
    }
}

int main() {
    FastIO
    input();
    solve();
    return 0;
}
