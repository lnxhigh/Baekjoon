#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

string S;
char A[3][3];

bool check(char x) {
    for (int r = 0; r < 3; r++) {
        bool line = true;
        for (int c = 0; c < 3; c++) {
            if (A[r][c] != x) line = false;
        }
        if (line) return true;
    }

    for (int c = 0; c < 3; c++) {
        bool line = true;
        for (int r = 0; r < 3; r++) {
            if (A[r][c] != x) line = false;
        }
        if (line) return true;
    }

    // 디버그 주의 ...
    bool diagA = true;
    bool diagB = true;

    for (int i = 0; i < 3; i++) {
        if (A[i][i] != x) diagA = false;
        if (A[i][2 - i] != x) diagB = false;
    }

    if (diagA || diagB) return true;

    return false;
}

bool solve() {
    int x = 0, o = 0;

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (A[r][c] == 'X') x++;
            else if (A[r][c] == 'O') o++;
        }
    }

    if (!(x == o || x == o + 1)) return false;
    
    bool first = check('X');
    bool last = check('O');
    
    if (first && last) return false;
    else if (first && !last) return x == o + 1;
    else if (!first && last) return x == o;
    
    return x + o == 9;
}

int main() {
    FastIO
    while (true) {
        cin >> S;
        if (S == "end") break;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                A[i][j] = S[i * 3 + j];
            }
        }

        string ans = solve() ? "valid" : "invalid";
        cout << ans << '\n';
    }

    return 0;
}
