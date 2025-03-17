#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 51;

int R, C, T;
char A[MAX][MAX][MAX];

int D[128];
long long Ans[4] = { 0, 0, 0, 0 };

int main() {
    FastIO
    cin >> R >> C >> T;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j][0];
        }
    }

    for (int cnt = 1; cnt <= min(R, C); cnt++) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                A[i][j][cnt] = A[i][j][0];
                int m = min({ cnt, R - 1 - i, C - 1 - j });

                for (int k = 1; k <= m && A[i][j][cnt] == '.'; k++) {
                    A[i][j][cnt] = A[i + k][j + k][0];
                }
            }
        }
    }

    D['R'] = 0, D['G'] = 1, D['B'] = 2, D['.'] = 3;

    for (int cnt = 0; cnt < min(T, min(R, C)); cnt++) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (i == 0 || j == 0) {
                    Ans[D[A[i][j][cnt]]]++;
                }
            }
        }
    }

    if (T <= min(R, C)) {
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                Ans[D[A[i][j][T - 1]]]++;
            }
        }
    }
    else {
        int tmp[4] = { 0, 0, 0, 0 };

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                char color = A[i][j][min(R, C)];
                Ans[D[color]]++;
                if (i == 0 || j == 0) tmp[D[color]]++;
            }
        }

        int cnt = T - min(R, C) - 1;
        for (int k = 0; k < 4; k++) {
            Ans[k] += (long long) tmp[k] * cnt;
        }
    }
    
    cout << Ans[0] << '\n';
    cout << Ans[1] << '\n';
    cout << Ans[2] << '\n';

    return 0;
}
