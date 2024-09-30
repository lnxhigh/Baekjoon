#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

const int N = 3;
const int A[N] = { 1, 2, 3 };

const int K = 10001;
int D[K];

int main() {
    FastIO
    
    D[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = A[i]; j < K; j++) {
            D[j] += D[j - A[i]];
        }
    }

    int T; cin >> T;
    while (T--) {
        int X; cin >> X;
        cout << D[X] << '\n';
    }
    
    return 0;
}
