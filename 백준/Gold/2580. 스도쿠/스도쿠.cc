#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int sudoku[9][9];
vector< pair<int, int> > v;
int N;
bool finish;

void printSudoku(void) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool checkLine(int x, int i, int j) {
    for (int r = 0; r < 9; r++) {
        if (x == sudoku[r][j]) return false;
    }
    for (int c = 0; c < 9; c++) {
        if (x == sudoku[i][c]) return false;
    }
    return true;
}

bool checkBox(int x, int i, int j) {
    pair<int, int> center;
    if (i >= 0 and i < 3) center.first = 1;
    else if (i >= 3 and i < 6) center.first = 4;
    else center.first = 7;

    if (j >= 0 and j < 3) center.second = 1;
    else if (j >= 3 and j < 6) center.second = 4;
    else center.second = 7;

    for (int r = center.first-1; r <= center.first+1; r++) {
        for (int c = center.second-1; c <= center.second+1; c++) {
            if (sudoku[r][c] == x) return false;
        }
    }
    return true;
}

bool isPromising(int x, int i, int j) {
    if (not checkLine(x, i, j)) return false;
    if (not checkBox(x, i, j)) return false;
    return true;
}

void dfs(int i) {
    if (i == N) {
        printSudoku();
        exit(EXIT_SUCCESS);
    }
    
    int r = v[i].first;
    int c = v[i].second;

    for (int x = 1; x <= 9; x++) {
        if (isPromising(x, r, c)) {
            sudoku[r][c] = x;
            dfs(i+1);
            sudoku[r][c] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0) v.push_back({i, j});
        }
    }

    N = v.size();
    dfs(0);
    
    return 0;
}