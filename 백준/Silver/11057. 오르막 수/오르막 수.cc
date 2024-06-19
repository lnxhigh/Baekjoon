#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 1001;
const int DIV = 10007;

int D[N_MAX][10];

int main() {
    cin >> N;

    D[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < 10; k++) {
            for (int x = k; x < 10; x++) {
                D[i+1][x] += D[i][k];
                D[i+1][x] %= DIV;
            }
        }
    }

    int res = 0;
    for (int k = 0; k < 10; k++) {
        res += D[N][k];
        res %= DIV;
    }
    cout << res << '\n';
    
    return 0;
}
