#include <bits/stdc++.h>
using namespace std;
using xy = pair<int,int>;

int N, R, C;
const int MAX = 1 << 3;
int office[MAX][MAX];
vector<xy> cctvLoc;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

enum Map { EMPTY, ONE, TWO, THREE, FOUR, FIVE, WALL };

void monitor(xy loc, vector<xy> dirs, int arr[MAX][MAX]) {
    for (xy dir : dirs) {
        int nextX = loc.first, nextY = loc.second;
        while (true) {
            nextX += dir.first, nextY += dir.second;
            if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) break;
            if (office[nextX][nextY] == Map::WALL) break;
            arr[nextX][nextY] = -1;
        }
    }
}

vector<xy> getDirs(Map cctv, int dir) {
    vector<xy> res;
    vector<int> dirs;

    if      (cctv == Map::ONE)   { dirs = { dir }; }
    else if (cctv == Map::TWO)   { dirs = { dir, (dir+2) % 4 }; }
    else if (cctv == Map::THREE) { dirs = { dir, (dir+1) % 4 }; }
    else if (cctv == Map::FOUR)  { dirs = { dir, (dir+1) % 4, (dir+3) % 4 }; }
    else if (cctv == Map::FIVE)  { dirs = { dir, (dir+1) % 4, (dir+2) % 4, (dir+3) % 4 }; }

    for (int k : dirs) {
        xy v = { dx[k], dy[k] };
        res.push_back(v);
    }

    return res;
}

int CountBlindSpot(int arr[MAX][MAX]) {
    int res = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (arr[r][c] == 0) res++;
        }
    }
    
    return res;
}

int simulate(int state) {
    // Copy
    int newOffice[MAX][MAX];
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            newOffice[r][c] = office[r][c];
        }
    }

    // Simulate
    for (int i = 0; i < N; i++) {
        int k = i << 1;
        int mask = (1 << k) + (1 << (k+1));
        int dir = (state & mask) >> k;

        xy loc = cctvLoc[i];
        Map cctv = (Map) office[loc.first][loc.second];
        vector<xy> dirs = getDirs(cctv, dir);
        monitor(loc, dirs, newOffice);
    }

    // Count
    int res = CountBlindSpot(newOffice);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // Input
    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> office[r][c];
            if (office[r][c] != Map::EMPTY && office[r][c] != Map::WALL) {
                cctvLoc.push_back({ r, c });
            }
        }
    }

    N = cctvLoc.size();

    // Simulate
    int res = 1 << 10;
    for (int s = 0; s < (1 << (N << 1)); s++) {
        int tmp = simulate(s);
        res = min(res, tmp);
    }
    cout << res << '\n';

    return 0;
}
