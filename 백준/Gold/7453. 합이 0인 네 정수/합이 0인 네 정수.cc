#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 12;

int main() {
    FastIO

    int N; cin >> N;
    vector<int> A(N), B(N), C(N), D(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    int M = N * N;
    vector<int> X, Y;
    X.reserve(M), Y.reserve(M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X.push_back(A[i] + B[j]);
            Y.push_back(C[i] + D[j]);
        }
    }
    
    sort(Y.begin(), Y.end());
    
    long long res = 0;
    for (int i : X) {
        int cnt = upper_bound(Y.begin(), Y.end(), -i) - lower_bound(Y.begin(), Y.end(), -i);
        res += (long long) cnt;
    }

    cout << res << '\n';
    return 0;
}
