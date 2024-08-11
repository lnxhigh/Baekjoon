#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 1 << 19;
int D[N_MAX];

int solve(int N, int D[N_MAX]) {
    if (N == 0) return 0;

    int X = round(0.15 * N);
    int S = 0;
    for (int i = X; i < N - X; i++) S += D[i];

    double avg = (double) S / (double) (N - X * 2);
    int res = round(avg);
    return res;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> D[i];
    sort(D, D + N);
    int res = solve(N, D);
    cout << res << '\n';
    return 0;
}
