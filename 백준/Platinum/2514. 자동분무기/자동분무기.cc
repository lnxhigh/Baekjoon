#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int M, K;
int D[8][8];
int R[8], C[8];

int main() {
    FastIO
    cin >> M >> K;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int X; cin >> X;
            D[i][j] = X - M;
        }
    }

    int S = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            S += D[i][j];
            R[i] += D[i][j];
            C[j] += D[i][j];
        }
    }

    int X[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            X[i][j] = (R[i] + C[j] - 2 * (S / 15) - 7 * D[i][j]);
            X[i][j] /= 7;
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c = (X[i][j] > 0) ? '+' : (X[i][j] < 0) ? '-' : '.';
            cout << c << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
