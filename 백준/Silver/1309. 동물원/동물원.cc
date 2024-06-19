#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 100001;
const int DIV = 9901;

int D[N_MAX][2][2];

int main() {
    cin >> N;

    D[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        D[i+1][0][0] = (D[i][0][0] + D[i][0][1] + D[i][1][0]) % DIV;
        D[i+1][0][1] = (D[i][0][0] + D[i][1][0]) % DIV;
        D[i+1][1][0] = (D[i][0][0] + D[i][0][1]) % DIV;
    }

    int res = (D[N][0][0] + D[N][0][1] + D[N][1][0]) % DIV;
    cout << res << '\n';
    return 0;
}
