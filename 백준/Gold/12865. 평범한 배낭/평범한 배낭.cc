#include <bits/stdc++.h>
using namespace std;

int N, K;
const int N_MAX = 101;
const int K_MAX = 100001;

int W[N_MAX], V[N_MAX];
int D[N_MAX][K_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= K; w++) {
            if (W[i] > w) {
                D[i][w] = D[i-1][w];
            }
            else {
                D[i][w] = max(D[i-1][w], D[i-1][w-W[i]] + V[i]);
            }
        }
    }

    cout << D[N][K] << '\n';
    return 0;
}
