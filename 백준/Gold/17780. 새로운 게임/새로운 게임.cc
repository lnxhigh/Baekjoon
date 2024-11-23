#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

enum Color { 
    WHITE = 0, RED = 1, BLUE = 2 
};

struct Piece { 
    int n, x, y, dir;
    Piece() { 
        n = 0, x = 0; y = 0; dir = 0; 
    }
    Piece(int _n, int _x, int _y, int _dir) { 
        n = _n, x = _x; y = _y; dir = _dir; 
    }
};

int N, K;
int State[16][16];
vector<Piece> Chess[16][16];
Piece P[16];

// →, ←, ↑, ↓
int dx[4] = { 0, 0, -1, +1 };
int dy[4] = { +1, -1, 0, 0 };

void input() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> State[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int x, y, dir;
        cin >> x >> y >> dir;
        --x, --y, --dir;
        P[i] = Piece(i, x, y, dir);
        Chess[x][y].push_back(P[i]);
    }
}

bool inside(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    return true;
}

void move(int i) {
    int x = P[i].x;
    int y = P[i].y;
    auto iter = Chess[x][y].begin();

    // 가장 아래에 있는 말만 이동할 수 있다
    if (i != iter->n) {
        return;
    }

    int &d = P[i].dir;
    int nx = x + dx[d], ny = y + dy[d];

    // 파란색 방향 전환
    if (!inside(nx, ny) || State[nx][ny] == Color::BLUE) {
        d ^= 1;
        nx = x + dx[d], ny = y + dy[d];
    }
    if (!inside(nx, ny) || State[nx][ny] == Color::BLUE) return;
    
    // 빨간색 순서 역전
    if (State[nx][ny] == Color::RED) {
        reverse(Chess[x][y].begin(), Chess[x][y].end());
    }

    // 이동
    for (auto& p : Chess[x][y]) {
        int n = p.n;
        P[n].x = nx, P[n].y = ny;
        Chess[nx][ny].push_back(P[n]);
    }
    Chess[x][y].clear();
}

int main() {
    FastIO
    input();

    int turn = 0;
    bool gameover = false;
    while (!gameover && turn <= 1000) {
        turn++;
        for (int i = 0; i < K; i++) {
            move(i);
            
            int cnt = Chess[P[i].x][P[i].y].size();
            if (cnt >= 4) { gameover = true; break; }
        }
    }
    
    if (turn > 1000) turn = -1;
    cout << turn << '\n';
    return 0;
}
