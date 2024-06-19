#include <bits/stdc++.h>
using namespace std;

int N, K;
const int N_MAX = 201, K_MAX = 201;
const int DIV = 1000000000;
int D[N_MAX][K_MAX];

int main() {
    cin >> N >> K;
    
    D[0][0] = 1;
    for (int i = 0; i <= N; i++) {
        for (int k = 0; k < K; k++) {
            for (int x = 0; x <= N; x++) {
                if (i+x >= N_MAX) continue;
                D[i+x][k+1] = (D[i+x][k+1] + D[i][k]) % DIV;
            }
        }
    }

    cout << D[N][K] << '\n';
    return 0;
}
