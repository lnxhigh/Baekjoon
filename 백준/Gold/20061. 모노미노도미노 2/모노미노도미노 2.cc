#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
bool G[10][10], B[10][10];

bool check(int idx, bool all, bool D[10][10]) {
    int cnt = 0;
    for (int col = 0; col < 4; col++) {
        if (D[idx][col]) cnt++;
    }

    if (all) return cnt >= 4;
    return cnt > 0;
}

void clear(int idx, bool D[10][10]) {
    for (int col = 0; col < 4; col++) {
        D[idx][col] = false;
    }
}

void move(int idx, int len, bool D[10][10]) {
    for (int col = 0; col < 4; col++) {
        if (!D[idx][col]) continue;
        
        D[idx][col] = false;
        D[idx + len][col] = true;
    }
}

void first(int t, int x, int y, bool D[10][10]) {
    if (t == 1) {
        while (x + 1 < 10 && !D[x + 1][y]) x++;
        D[x][y] = true;
    }
    else if (t == 2) {
        while (x + 1 < 10 && !D[x + 1][y] && !D[x + 1][y + 1]) x++;
        D[x][y] = D[x][y + 1] = true;
    }
    else if (t == 3) {
        while (x + 2 < 10 && !D[x + 1][y] && !D[x + 2][y]) x++;
        D[x][y] = D[x + 1][y] = true;
    }
}

void second(bool D[10][10], int& score) {
    int cnt = 0, idx = -1;
    
    for (int row = 9; row >= 6; row--) {
        if (check(row, true, D)) {
            cnt++;
            idx = row - 1;
            clear(row, D);
        }
    }
    
    score += cnt;
    if (cnt == 0 || idx == -1) return;

    for (int row = idx; row >= 4; row--) {
        move(row, cnt, D);
    }
}

void third(bool D[10][10]) {
    int cnt = 0;
    for (int row = 4; row <= 5; row++) {
        if (check(row, false, D)) cnt++;
    }
    if (cnt == 0) return;

    for (int row = 9; row > 9 - cnt; row--) {
        clear(row, D);
    }
    for (int row = 9 - cnt; row >= 4; row--) {
        move(row, cnt, D);
    } 
}

int main() {
    FastIO
    cin >> N;

    int score = 0;
    int cnt = 0;

    while (N--) {
        int t, x, y; cin >> t >> x >> y;

        first(t, x, y, G);
        second(G, score);
        third(G);

        if (t != 1) t = 5 - t;
        first(t, y, x, B);
        second(B, score);
        third(B);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (G[i][j]) cnt++;
            if (B[i][j]) cnt++;
        }
    }

    cout << score << '\n';
    cout << cnt << '\n';
    return 0;
}
