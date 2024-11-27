#include <iostream>
#include <string>
using namespace std;

string X, Y;
int M, N;
int DP[1001][1001] = {0,};

int main(void) {
    cin >> X >> Y;
    M = X.length(); N = Y.length();

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (X[i-1] == Y[j-1]) { DP[i][j] = DP[i-1][j-1] + 1; }
            else { DP[i][j] = max(DP[i-1][j], DP[i][j-1]); }
        }
    }

    cout << DP[M][N] << endl;

    return 0;
}