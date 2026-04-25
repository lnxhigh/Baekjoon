#include <iostream>
#include <string>
#include <vector>
using namespace std;

string X, Y;
int M, N;
int DP[1001][1001] = {0,};
char Direction[1001][1001];
vector<char> LCS;

int main(void) {
    cin >> X >> Y;
    M = X.length(); N = Y.length();

    for (int i = 0; i <= M; i++) { Direction[i][0] = 'u'; }
    for (int j = 0; j <= N; j++) { Direction[0][j] = 'l'; }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (X[i-1] == Y[j-1]) { 
                DP[i][j] = DP[i-1][j-1] + 1; 
                Direction[i][j] = 'b';
            }
            else { 
                if (DP[i-1][j] > DP[i][j-1]) {
                    DP[i][j] = DP[i-1][j];
                    Direction[i][j] = 'u';
                }
                else {
                    DP[i][j] = DP[i][j-1];
                    Direction[i][j] = 'l';
                }
            }
        }
    }

    cout << DP[M][N] << endl;

    int i = M, j = N;
    char dir = '\0';

    while (i != 0 and j != 0) {
        dir = Direction[i][j];
        if (dir == 'l') { j += -1; }
        else if (dir == 'u') { i += -1; }
        if (dir == 'b') {
            LCS.push_back(X[i-1]);
            i += -1; j += -1;
        }
    }

    for (vector<char>::reverse_iterator iter = LCS.rbegin(); iter != LCS.rend(); iter++ ) { 
        cout << *iter;
    } 
    cout << endl;

    return 0;
}
