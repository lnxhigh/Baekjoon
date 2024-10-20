#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MAX = 1 << 5;
int64 S[MAX][MAX];

// The key in the boxes forms a cycle when a box is destroyed
// We can obtain all keys if the number of cycles is small enough
// i.e. Find all cases that the number of cycles is less than or equal to M
// Stirling Numbers of the first kind fits the problem

int main() {
    int64 N, M; cin >> N >> M;

    S[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int k = 1; k <= i + 1; k++) {
            S[i+1][k] = 1LL * i * S[i][k] + S[i][k-1];
        }
    }

    int64 A = 0, B = 0;
    for (int64 i = 0; i <= M; i++) A += S[N][i];
    for (int64 i = 0; i <= N; i++) B += S[N][i];

    int64 G = gcd(A, B);
    A /= G, B /= G;
    cout << A << '/' << B << '\n';
    return 0;
}
