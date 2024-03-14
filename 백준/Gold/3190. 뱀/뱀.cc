#include <bits/stdc++.h>
#define N_MAX 101
#define T_MAX 10001

using namespace std;

int N, K, L;
int board[N_MAX][N_MAX] = {0,};
enum { FREE, APPLE, SNAKE };
enum { LEFT, RIGHT, DOWN, UP };
int t[T_MAX] = {0,};
char d[T_MAX];
deque<pair<int,int>> snake;

void move(pair<int,int> &loc, int dir) {
    int dr[4] = { 0,  0, +1, -1};
    int dc[4] = {-1, +1,  0,  0};

    loc.first += dr[dir];
    loc.second += dc[dir];
}

void drift(int &dir, char C) {
    if (dir == LEFT) {
        if (C == 'L') dir = DOWN;
        else if (C == 'D') dir = UP;
    }
    else if (dir == RIGHT) {
        if (C == 'L') dir = UP;
        else if (C == 'D') dir = DOWN;
    }
    else if (dir == DOWN) {
        if (C == 'L') dir = RIGHT;
        else if (C == 'D') dir = LEFT;
    }
    else if (dir == UP) {
        if (C == 'L') dir = LEFT;
        else if (C == 'D') dir = RIGHT;
    }
    
    return;
}

// Snake Game
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> K;
    for (int k = 0; k < K; k++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = APPLE;
    }
    
    cin >> L;
    for (int i = 0; i < L; i++) {
        int X;
        char C;
        cin >> X >> C;
        t[X]++;
        d[X] = C;
    }

    int res = 0;
    pair<int,int> head = {1,1};
    pair<int,int> tail = {1,1};
    snake.push_front(head);
    int dir = RIGHT;

    while (true) {
        res++;
        head = snake.back();
        tail = snake.front();

        move(head, dir);
        
        bool over = false;
        int x = head.first, y = head.second;
        if (x <= 0 or x > N) over = true;
        if (y <= 0 or y > N) over = true;
        for (pair<int,int> body : snake) {
            if (head == body) over = true;
            if (over) break;
        }
        if (over) break;

        if (board[x][y] == APPLE) {
            board[x][y] = FREE;
            snake.push_back({x, y});
        }
        else if (board[x][y] == FREE) {
            snake.pop_front();
            snake.push_back({x, y});
        }

        if (t[res] > 0) {
            drift(dir, d[res]);
        }
    }

    cout << res << '\n';

    return 0;
}