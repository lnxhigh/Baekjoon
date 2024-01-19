#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using xy = pair<int,int>;

int R, C, T;
int room[51][51] = {0,};
vector<xy> A;

void input(int &R, int &C, int &T, int room[51][51]) {
    cin >> R >> C >> T;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> room[r][c];
            if (room[r][c] == -1) A.push_back({r,c});
        }
    }
    
}

void print(int room[51][51]) {
    cout << '\n';
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cout << room[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void diffusion(int room[51][51]) {
    int amount[51][51] = {0,};
    int dust[51][51] = {0,};
    vector<xy> move = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            amount[r][c] = room[r][c] / 5;
            dust[r][c] = room[r][c];
        }
    }
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (room[r][c] == -1) continue;

            for (xy m : move) {
                int x = r + m.first, y = c + m.second;
                if (x < 0 or x >= R) continue;
                if (y < 0 or y >= C) continue;
                if (room[x][y] == -1) continue;
                if (amount[x][y] <= 0) continue;

                dust[r][c] += amount[x][y];
                dust[x][y] -= amount[x][y];
            }
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            room[r][c] = dust[r][c];
        }
    }
}

void circulation(int room[51][51], vector<xy> A) {
    int r, c, x, y;
    // CCW
    x = A[0].first;
    y = A[0].second;

    c = 0;
    for (r = x-1; r >= 0; r--) {
        room[r+1][c] = room[r][c];
    }

    r = 0;
    for (c = 1; c < C; c++) {
        room[r][c-1] = room[r][c];
    }

    c = C-1;
    for (r = 1; r <= x; r++) {
        room[r-1][c] = room[r][c];
    }
    
    r = x;
    for (c = C-2; c >= 0; c--) {
        room[r][c+1] = room[r][c];
    }

    room[x][y] = -1;
    room[x][y+1] = 0;

    // CW
    x = A[1].first;
    y = A[1].second;

    c = 0;
    for (r = x+1; r < R; r++) {
        room[r-1][c] = room[r][c];
    }

    r = R-1;
    for (c = 1; c < C; c++) {
        room[r][c-1] = room[r][c];
    }

    c = C-1;
    for (r = R-2; r >= x; r--) {
        room[r+1][c] = room[r][c];
    }

    r = x;
    for (c = C-2; c >= 0; c--) {
        room[r][c+1] = room[r][c];
    }

    room[x][y] = -1;
    room[x][y+1] = 0;

}

int amount(int room[51][51]) {
    int sum = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            sum += room[r][c];
        }
    }
    sum += 2;
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    input(R, C, T, room);
    for (int t = 0; t < T; t++) {
        diffusion(room);
        circulation(room, A);
    }
    cout << amount(room);
    
    return 0;
}