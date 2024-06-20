#include <bits/stdc++.h>
using namespace std;

int TC;

int N, K;
const int N_MAX = 21, K_MAX = 10001;

int A[N_MAX];
int D[N_MAX][K_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> TC;
    while (TC--) {
        memset(A, 0, sizeof(A));
        memset(D, 0, sizeof(D));
        
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }
        cin >> K;

        for (int i = 0; i <= N; i++) D[i][0] = 1;

        for (int i = 1; i <= N; i++) {
            for (int k = 1; k <= K; k++) {
                if (k < A[i]) D[i][k] = D[i-1][k];
                else D[i][k] = D[i-1][k] + D[i][k-A[i]];
            }
        }
        
        cout << D[N][K] << '\n';
    }

    return 0;
}
