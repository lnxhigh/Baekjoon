#include <bits/stdc++.h>
using namespace std;

int N, M, K;
const int N_MAX = 1 << 5, M_MAX = 1 << 3;
const int K_MAX = 1 << 14;

int W[N_MAX], X[M_MAX];
bool D[N_MAX][K_MAX];

int main() {
    // Input
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> W[i];
        K += W[i];
    }
    cin >> M;
    for (int i = 1; i <= M; i++) {
        cin >> X[i];
    }

    // DP 배열 채우기
    for (int i = 0; i <= N; i++) {
        D[i][0] = true;
    }
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= K; k++) {
            D[i][k] = D[i-1][k] || D[i-1][abs(k-W[i])] || D[i-1][k+W[i]];
        }
    }
    
    // 결과 출력
    for (int i = 1; i <= M; i++) {
        char ans = (X[i] > K) ? 'N' : D[N][X[i]] ? 'Y' : 'N';
        cout << ans << ' ';
    }
    cout << '\n';

    return 0;
}
