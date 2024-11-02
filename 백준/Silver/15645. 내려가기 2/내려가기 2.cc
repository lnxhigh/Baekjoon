#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
int A[100000][3];
int D[100000][3];

int solve(bool maxFlag) {
    int value = maxFlag ? 0 : 1 << 30;
    for (int i = 0; i < N; i++) {
        fill(D[i], D[i] + 3, value);
    }

    for (int i = 0; i < 3; i++) {
        D[0][i] = A[0][i];
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k : { j - 1, j, j + 1 }) {
                if (k >= 0 && k < 3) {
                    if (maxFlag) D[i][j] = max(D[i][j], D[i-1][k] + A[i][j]);
                    else D[i][j] = min(D[i][j], D[i-1][k] + A[i][j]);
                }
            }
        }
    }

    int M = max({ D[N-1][0], D[N-1][1], D[N-1][2] });
    int m = min({ D[N-1][0], D[N-1][1], D[N-1][2] });
    return maxFlag ? M : m;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    cout << solve(true) << ' ';
    cout << solve(false) << '\n';
    return 0;
}
