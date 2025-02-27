#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MOD = 1'000'000'007;

int N;
int D[1515 + 1][15];

int main() {
    FastIO
    cin >> N;
    
    D[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int r = 0; r < 15; r++) {
            for (int x = 0; x < 15; x++) {
                if ((10 * x + 1) % 15 == r) {
                    D[i][r] = (D[i][r] + D[i - 1][x]) % MOD;
                }
                if ((10 * x + 5) % 15 == r) {
                    D[i][r] = (D[i][r] + D[i - 1][x]) % MOD;
                }
            }
        }
    }
    
    cout << D[N][0] << '\n';
    return 0;
}
