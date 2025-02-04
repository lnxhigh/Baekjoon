#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 9;

int N;
double P[MAX], Q[MAX], R[MAX];

int main() {
    FastIO
    cin >> N;
    cout << setprecision(16);

    for (int i = 0; i < N; i++) cin >> Q[i];
    for (int i = 0; i < N; i++) cin >> R[i];
    for (int i = N - 1; i; i--) R[i - 1] += R[i];

    double x = 0;
    for (int i = 0; i < N; i++) {
        P[i] = Q[i] / R[i];
        x += P[i];
    }

    for (int i = 0; i < N; i++) {
        cout << P[i] / x << ' ';
    }
    cout << '\n';
    return 0;
}
