#include <iostream>
#include <utility>
#include <tuple>
#include <queue>
using namespace std;

int C, R, H;
int tomato[100][100][100];
int visited[100][100][100] = {0,};

int bfs(int tomato[100][100][100]) {
    int res = 0;
    queue<pair<tuple<int,int,int>, int>> q;

    // Init
    for (int h = 0; h < H; h++) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (tomato[r][c][h] == 1) {
                    q.push({make_tuple(r, c, h), 0});
                    visited[r][c][h] = 1;
                }
            }
        }           
    }

    // Search
    int dr[6] = {-1, +1, 0, 0, 0, 0};
    int dc[6] = {0, 0, -1, +1, 0, 0};
    int dh[6] = {0, 0, 0, 0, -1, +1};

    while (not q.empty()) {
        tuple<int,int,int> cur = q.front().first;
        int depth = q.front().second;
        res = depth;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int r = get<0>(cur) + dr[i];
            int c = get<1>(cur) + dc[i];
            int h = get<2>(cur) + dh[i];            
            tuple<int,int,int> next = make_tuple(r, c, h);

            if (r < 0 || r >= R) continue;
            if (c < 0 || c >= C) continue;
            if (h < 0 || h >= H) continue;
            if (visited[r][c][h]++) continue;

            if (tomato[r][c][h] == -1) continue;
            else if (tomato[r][c][h] == 1) continue;
            else if (tomato[r][c][h] == 0) {
                tomato[r][c][h] = 1;
                q.push( {next, depth+1} );
            }
        }
    }
    return res;
}

bool check(int tomato[100][100][100]) {
    bool res = true;
    for (int h = 0; h < H; h++) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (tomato[r][c][h] == 0) { res = false; }
            }
        }           
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> C >> R >> H;
    for (int h = 0; h < H; h++) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                cin >> tomato[r][c][h];
            }
        }           
    }
    
    int res = bfs(tomato);
    if (not check(tomato)) res = -1;
    cout << res << '\n';

    return 0;
}