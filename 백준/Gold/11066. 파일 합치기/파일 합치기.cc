#include <iostream>
using namespace std;

int T, K;
int sizeFromTo[501][501];
int DP[501][501];

int main(void) {
    int i, j, k, t, v;
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    for (t = 0; t < T; t++) {
        cin >> K;
        for (k = 1; k <= K; k++) {
            cin >> sizeFromTo[k][k];
            DP[k][k] = 0;
        }

        for (i = K; i >= 1; i--) {
            for (j = i+1; j <= K; j++) {
                sizeFromTo[i][j] = sizeFromTo[i][i] + sizeFromTo[i+1][j];
            }
        }

        for (i = K; i >= 1; i--) {
            for (j = i+1; j <= K; j++) {
                v = DP[i][i] + DP[i+1][j] + sizeFromTo[i][j];
                DP[i][j] = v;
                for (k = i; k < j; k++) { 
                    v = DP[i][k] + DP[k+1][j] + sizeFromTo[i][j]; 
                    if (DP[i][j] > v) { DP[i][j] = v; } 
                }
            }
        }

        cout << DP[1][K] << '\n';
    }
    
    return 0;
}