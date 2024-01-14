#include <iostream>
#include <queue>
#include <utility>
using namespace std;
using xy = pair<int,int>;

int N, M;
char board[11][11];
xy red, blue, destination;
typedef struct marble {
    xy red;
    xy blue;
} Marble;
queue<pair<Marble, int>> q;

Marble marble;

void input(char board[11][11]) {
    cin >> N >> M;

    for (int r = 0; r < N; r++) {
        char line[11];
        cin >> line;
        for (int c = 0; c < M; c++) {
            board[r][c] = line[c];
            char x = board[r][c];
            if (x == 'R') { red = {r,c}; } 
            else if (x == 'B') { blue = {r,c}; }
            else if (x == 'O') { destination = {r,c}; }
        }
    }

    board[red.first][red.second] = '.';
    board[blue.first][blue.second] = '.';

    marble.red = red;
    marble.blue = blue;
}

void print(Marble marble, char board[11][11]) {
    xy red = marble.red;
    xy blue = marble.blue;
    board[red.first][red.second] = 'R';
    board[blue.first][blue.second] = 'B';
    board[destination.first][destination.second] = 'O';

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    board[red.first][red.second] = '.';
    board[blue.first][blue.second] = '.';
}

Marble moveTo(Marble marble, int i, char board[11][11]) {
    xy red = marble.red;
    xy blue = marble.blue;
    int n_red_moved = 0, n_blue_moved = 0;

    // Up Down Left Right
    int dx[4] = {-1,+1, 0, 0};
    int dy[4] = { 0, 0,-1,+1};

    while (board[red.first][red.second] == '.') {
        red.first += dx[i];
        red.second += dy[i];
        n_red_moved++;
    }
    
    while (board[blue.first][blue.second] == '.') {
        blue.first += dx[i];
        blue.second += dy[i];
        n_blue_moved++;
    }

    if (board[red.first][red.second] == '#') {
        red.first -= dx[i]; 
        red.second -= dy[i];
    }
    if (board[blue.first][blue.second] == '#') {
        blue.first -= dx[i];
        blue.second -= dy[i];
    }

    if (red == destination and blue == destination) {
        return { red, blue };
    }

    if (red == blue) {
        if (n_red_moved > n_blue_moved) {
            red.first -= dx[i];
            red.second -= dy[i];
        }
        else {
            blue.first -= dx[i];
            blue.second -= dy[i];
        }
    }
    
    return { red, blue };
}

int bfs() {
    q.push({marble, 1});
    while (not q.empty()) {
        Marble cur = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (depth > 10) return -1;

        for (int i = 0; i < 4; i++) {
            Marble next = moveTo(cur, i, board);
            if (next.red != destination and next.blue != destination) {
                q.push({ next, depth+1 });
            }
            else if (next.red == destination and next.blue != destination) {
                return depth; 
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    input(board);
    cout << bfs();
    return 0;
}