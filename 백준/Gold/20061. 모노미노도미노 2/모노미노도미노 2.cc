#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
bool D[10][10];

void putBlock(int t, int x, int y) {
    int row = x, col = y;
    
    if (t == 1) {
        row = x, col = y;
        while (row + 1 < 10 && !D[row + 1][col]) row++;
        D[row][col] = true;

        row = x, col = y;
        while (col + 1 < 10 && !D[row][col + 1]) col++;
        D[row][col] = true;
    }
    else if (t == 2) {
        row = x, col = y;
        while (row + 1 < 10 && !D[row + 1][col] && !D[row + 1][col + 1]) row++;
        D[row][col] = D[row][col + 1] = true;

        row = x, col = y;
        while (col + 2 < 10 && !D[row][col + 1] && !D[row][col + 2]) col++;
        D[row][col] = D[row][col + 1] = true;
    }
    else if (t == 3) {
        row = x, col = y;
        while (row + 2 < 10 && !D[row + 1][col] && !D[row + 2][col]) row++;
        D[row][col] = D[row + 1][col] = true;

        row = x, col = y;
        while (col + 1 < 10 && !D[row][col + 1] && !D[row + 1][col + 1]) col++;
        D[row][col] = D[row + 1][col] = true;
    }
}

bool checkAll(int idx, bool green) {
    if (green) {
        for (int col = 0; col < 4; col++) {
            if (!D[idx][col]) return false;
        }
    }
    else {
        for (int row = 0; row < 4; row++) {
            if (!D[row][idx]) return false;
        }
    }

    return true;
}

bool checkExist(int idx, bool green) {
    if (green) {
        for (int col = 0; col < 4; col++) {
            if (D[idx][col]) return true;
        }
    }
    else {
        for (int row = 0; row < 4; row++) {
            if (D[row][idx]) return true;
        }
    }

    return false;
}

int eraseLine() {
    // Green
    int rowcnt = 0, rowidx = -1;
    for (int row = 9; row >= 6; row--) {
        bool chk = checkAll(row, true);
        if (!chk) continue;
        
        rowcnt++, rowidx = row - 1;
        for (int col = 0; col < 4; col++) {
            D[row][col] = false;
        }
    }

    if (rowcnt) {
        for (int row = rowidx; row >= 4; row--) {
            for (int col = 0; col < 4; col++) {
                if (D[row][col]) {
                    D[row][col] = false;
                    D[row + rowcnt][col] = true;
                }
            }
        }
    }

    // Blue
    int colcnt = 0, colidx = -1;
    for (int col = 9; col >= 6; col--) {
        bool chk = checkAll(col, false);
        if (!chk) continue;

        colcnt++, colidx = col - 1;
        for (int row = 0; row < 4; row++) {
            D[row][col] = false;
        }
    }

    if (colcnt) {
        for (int col = colidx; col >= 4; col--) {
            for (int row = 0; row < 4; row++) {
                if (D[row][col]) {
                    D[row][col] = false;
                    D[row][col + colcnt] = true;
                }
            }
        }
    }

    return rowcnt + colcnt;
}

void pushLine() {
    // Green
    int rowcnt = 0;
    if (checkExist(4, true)) rowcnt++;
    if (checkExist(5, true)) rowcnt++;

    if (rowcnt) {
        for (int row = 9; row > 9 - rowcnt; row--) {
            for (int col = 0; col < 4; col++) {
                D[row][col] = false;
            }
        }
            
        for (int row = 9 - rowcnt; row >= 4; row--) {
            for (int col = 0; col < 4; col++) {
                if (D[row][col]) {
                    D[row][col] = false;
                    D[row + rowcnt][col] = true;
                }
            }
        }
    }

    // Blue
    int colcnt = 0;
    if (checkExist(4, false)) colcnt++;
    if (checkExist(5, false)) colcnt++;

    if (colcnt) {
        for (int col = 9; col > 9 - colcnt; col--) {
            for (int row = 0; row < 4; row++) {
                D[row][col] = false;
            }
        }
    
        for (int col = 9 - colcnt; col >= 4; col--) {
            for (int row = 0; row < 4; row++) {
                if (D[row][col]) {
                    D[row][col] = false;
                    D[row][col + colcnt] = true;
                }
            }
        }
    }
}

void print() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i >= 4 && j >= 4) continue;
            char c = D[i][j] ? 'X' : '.';
            cout << c << ' ';
        }
        cout<<endl;
    }
}

int main() {
    FastIO
    cin >> N;

    int score = 0;
    int cnt = 0;

    while (N--) {
        int t, x, y; cin >> t >> x >> y;
        putBlock(t, x, y);
        score += eraseLine();
        pushLine();
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (D[i][j]) {
                cnt++;
            }
        }
    }

    cout << score << '\n';
    cout << cnt << '\n';
    return 0;
}
