#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 3;
char cell;

int main() {
    int res = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cell;
            bool isWhite = ((i + j) % 2 == 0);
            bool isPiece = (cell == 'F');
            if (isWhite && isPiece) res++;
        }
    }

    cout << res << '\n';
    return 0;
}
