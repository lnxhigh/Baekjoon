#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N, M, K;
const int N_MAX = 1 << 9, M_MAX = 1 << 14;
int A[N_MAX][M_MAX];
int counts[N_MAX], maxIdx[M_MAX];

int main() {
    FastIO
    cin >> N >> M >> K;
    memset(maxIdx, -1, sizeof(maxIdx));
    
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < K; k++) {
            int j, t; cin >> j >> t;
            A[i][--j] = t;
        }
    }

    for (int m = 0; m < M; m++) {
        int maxSales = 0;
        for (int i = 0; i < N; i++) {
            if (A[i][m] > maxSales) {
                maxSales = A[i][m];
                maxIdx[m] = i;
            }
        }

        if (maxIdx[m] != -1) {
            counts[maxIdx[m]]++;
        }
    }

    int res = 0;
    for (int i = 0; i < N; i++) {
        if (counts[i] == K) res++;
    }

    int Q; cin >> Q;
    while (Q--) {
        int i, j, v; cin >> i >> j >> v;
        --i; --j;
        A[i][j] += v;

        if (A[i][j] > A[maxIdx[j]][j]) {
            int before = maxIdx[j];
            if (counts[before] == K) res--;
            counts[before]--;

            int after = i;
            maxIdx[j] = after;
            counts[after]++;
            if (counts[after] == K) res++;
        }

        cout << res << '\n';
    }

    return 0;
}
