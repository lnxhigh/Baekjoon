#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;

int R, C;
const int MAX = 1 << 7;
char A[MAX][MAX];

int main() {
    FastIO
    cin >> R >> C;

    vector<char> X, Y;
    For (r, R) {
        For (c, C) {
            char k; cin >> k;
            A[r][c] = k;
            
            if (k == '.') continue;
            X.push_back(r);
            Y.push_back(c);
        }
    }

    int minR = *min_element(X.begin(), X.end());
    int maxR = *max_element(X.begin(), X.end());
    int minC = *min_element(Y.begin(), Y.end());
    int maxC = *max_element(Y.begin(), Y.end());

    string res;
    if (A[(minR + maxR) / 2][minC] == '.') res = "LEFT";
    else if (A[(minR + maxR) / 2][maxC] == '.') res = "RIGHT";
    else if (A[minR][(minC + maxC) / 2] == '.') res = "UP";
    else if (A[maxR][(minC + maxC) / 2] == '.') res = "DOWN";
    
    cout << res << '\n';
    return 0;
}
