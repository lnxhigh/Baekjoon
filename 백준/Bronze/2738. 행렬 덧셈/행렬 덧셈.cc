#include <bits/stdc++.h>
using namespace std;
int R, C;
int arr[2][100][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> R >> C;
    for (int k = 0; k < 2; k++) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                cin >> arr[k][r][c];
            }
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cout << arr[0][r][c] + arr[1][r][c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}