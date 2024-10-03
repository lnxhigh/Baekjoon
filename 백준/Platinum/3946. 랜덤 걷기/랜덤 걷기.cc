#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

double solve(int N, double L, double R) {
    const double M = 1 - L - R;

    // D[N][K]: Probability that the rightmost position is K in N trials
    vector<vector<double>> D(N + 2, vector<double>(N + 2, 0));

    D[0][0] = 1;
    for (int n = 1; n <= N; n++) {
        // k = 0
        D[n][0] = L * (D[n-1][0] + D[n-1][1]) + M * D[n-1][0]; // Left. Stay.

        // 1 <= k <= N
        for (int k = 1; k <= n; k++) {
            D[n][k] = L * D[n-1][k+1] + M * D[n-1][k] + R * D[n-1][k-1]; // Left. Stay. Right
        }
    }

    double P = 0.0;
    for (int k = 0; k <= N; k++) P += k * D[N][k];
    return P;
}

int main() {
    FastIO
    cout << fixed << setprecision(4);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        double L, R; cin >> L >> R;
        double P = solve(N, L, R);
        cout << P << '\n';
    }

    return 0;
}
