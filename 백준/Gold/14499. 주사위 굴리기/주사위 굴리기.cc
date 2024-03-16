#include <bits/stdc++.h>
using namespace std;

int R, C;
int x, y;
int K, dir;

int Map[20][20] = {0,};

enum { NONE, EAST, WEST, NORTH, SOUTH, TOP, BOTTOM };
int dice[7] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> R >> C;
    cin >> x >> y;
    cin >> K;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> Map[r][c];
        }
    }

    for (int k = 0; k < K; k++) {
        // E W N S
        int dr[5] = {0, 0, 0, -1, +1};
        int dc[5] = {0, +1, -1, 0, 0};

        cin >> dir;
        int xnew = x + dr[dir];
        int ynew = y + dc[dir];

        if (xnew < 0 || xnew >= R) continue;
        if (ynew < 0 || ynew >= C) continue;

        int old[7];
        for (int i = 0; i < 7; i++) {
            old[i] = dice[i];
        }

        if (dir == EAST) {
            dice[BOTTOM] = old[EAST];
            dice[EAST] = old[TOP];
            dice[TOP] = old[WEST];
            dice[WEST] = old[BOTTOM];
        }
        else if (dir == WEST) {
            dice[BOTTOM] = old[WEST];
            dice[WEST] = old[TOP];
            dice[TOP] = old[EAST];
            dice[EAST] = old[BOTTOM];
        }
        else if (dir == NORTH) {
            dice[NORTH] = old[TOP];
            dice[TOP] = old[SOUTH];
            dice[SOUTH] = old[BOTTOM];
            dice[BOTTOM] = old[NORTH];
        }
        else if (dir == SOUTH) {
            dice[SOUTH] = old[TOP];
            dice[TOP] = old[NORTH];
            dice[NORTH] = old[BOTTOM];
            dice[BOTTOM] = old[SOUTH];
        }

        if (Map[xnew][ynew] == 0) {
            Map[xnew][ynew] = dice[BOTTOM];
        }
        else {
            dice[BOTTOM] = Map[xnew][ynew];
            Map[xnew][ynew] = 0;
        }

        x = xnew;
        y = ynew;

        cout << dice[TOP] << '\n';
    }
    
    return 0;
}