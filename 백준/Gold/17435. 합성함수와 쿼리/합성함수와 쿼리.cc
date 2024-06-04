#include <bits/stdc++.h>
using namespace std;
const int K_MAX = 19; // 2^k = N
const int M_MAX = 200001;

int M;
int F[K_MAX][M_MAX];
int Q;
int N, X;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> M;
    for (int i = 1; i <= M; i++) {
        cin >> F[0][i];
    }

    for (int k = 0; k < K_MAX-1; k++) {
        for (int i = 1; i <= M; i++) {
            F[k+1][i] = F[k][F[k][i]];
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> N >> X;
        for (int k = 0; k < K_MAX; k++) {
            if (N & (1 << k)) X = F[k][X];
        }
        cout << X << '\n';
    }

    return 0;    
}
