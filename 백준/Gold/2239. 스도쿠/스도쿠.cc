#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int M;
char answer[9][9] = {'0',};
char board[9][9] = {'0',};
vector<pair<int,int>> blank;
bool finish = false;

void input() {
    char line[10];

    for (int i = 0; i < 9; i++) {
        cin >> line;
        for (int j = 0; j < 9; j++) {
            board[i][j] = line[j];
            if (board[i][j] == '0') {
                M++;
                blank.push_back({i,j});
            }
        }
    }
}

bool checkRow(char n, int x, int y) {
    for (int c = 0; c < 9; c++) {
        if (board[x][c] == n) {
            return false;
        }
    }
    return true;
}

bool checkCol(char n, int x, int y) {
    for (int r = 0; r < 9; r++) {
        if (board[r][y] == n) return false;
    }
    return true;
}
bool checkSquare(char n, int x, int y) {
    x = x / 3 * 3;
    y = y / 3 * 3;

    for (int i = x; i < x+3; i++) {
        for (int j = y; j < y+3; j++) {
            if (board[i][j] == n) return false;
        }
    }
    return true;
}

bool check(char n, int x, int y) {
    if (not checkRow(n, x, y)) return false;
    if (not checkCol(n, x, y)) return false;
    if (not checkSquare(n, x, y)) return false;
    return true;
}

void update(char answer[9][9], char board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            answer[i][j] = board[i][j];
        }
    }
}

void print(char board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

void sudoku(int count) {
    if (finish) return;
    if (count == M) {
        finish = true;
        update(answer, board);
        return;
    }

    pair<int,int> xy = blank[count];
    int x = xy.first, y = xy.second;

    for (char n = '1'; n <= '9'; n++) {
        if (check(n, x, y)) {
            board[x][y] = n;
            sudoku(count+1);
            board[x][y] = '0';
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    input();
    sudoku(0);
    print(answer);

    return 0;
}