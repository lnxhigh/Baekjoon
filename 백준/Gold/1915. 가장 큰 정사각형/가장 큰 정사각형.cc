#include <bits/stdc++.h>
using namespace std;

int R, C;
const int MAX = 1001;

bool Array[MAX][MAX];
int D[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            char letter;
            cin >> letter;
            Array[i][j] =  (letter == '1');
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            int r = D[i-1][j-1];
            
            int cnt = 0;
            for (int k = 0; k <= r; k++) {
                if (!Array[i-k][j] || !Array[i][j-k]) {
                    break;
                }
                cnt++;
            }

            D[i][j] = cnt;
        }
    }

    int res = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            res = max(res, D[i][j]);
        }
    }

    int area = res * res;
    cout << area << '\n';
    
    return 0;
}
