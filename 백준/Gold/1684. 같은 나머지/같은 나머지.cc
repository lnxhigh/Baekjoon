#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) { cin >> A[i]; }

    int K = N * (N-1) / 2;
    vector<int> D(K);
    int L = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            D[L++] = abs(A[i] - A[j]);
        }
    }

    // Assume N != 1
    int X = D[0];
    for (int i = 1; i < K; i++) {
        X = __gcd(X, D[i]);
    }

    cout << X << '\n';
    return 0;
}
