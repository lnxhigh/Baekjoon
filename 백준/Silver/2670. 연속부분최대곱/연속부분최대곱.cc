#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 10000;
double A[MAX];
double D[MAX];

int main() {
    FastIO
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        D[i] = A[i];
    }

    for (int i = 1; i < N; i++) {
        D[i] = max(D[i], D[i - 1] * A[i]);
    }

    double ans = *max_element(D, D + N);
    cout << fixed << setprecision(3);
    cout << ans << '\n';
    return 0;
}
