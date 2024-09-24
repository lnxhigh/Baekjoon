#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int solve(int N, const vector<vector<int>> &A) {
    vector<int> L(N), U(N);
    L[0] = A[1][0], U[0] = A[0][0];
    L[1] = A[0][0] + A[1][1], U[1] = A[1][0] + A[0][1];

    for (int i = 2; i < N; i++) {
        L[i] = max(U[i-1], U[i-2]) + A[1][i];
        U[i] = max(L[i-1], L[i-2]) + A[0][i];
    }
    
    return max(L[N-1], U[N-1]);
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<vector<int>> A(2, vector<int>(N));
        for (vector<int> &row : A) {
            for (int &x : row) cin >> x;
        }

        int res = solve(N, A);
        cout << res << '\n';
    }
    
    return 0;
}
