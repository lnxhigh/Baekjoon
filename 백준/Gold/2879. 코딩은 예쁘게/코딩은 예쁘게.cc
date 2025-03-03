#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int N;
int X[MAX], Y[MAX];
int D[MAX];

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> Y[i];
    }
    for (int i = 0; i < N; i++) {
        D[i] = Y[i] - X[i];
    }

    int ans = 0;

    while (true) {
        int k = -1;
        for (int i = 0; i < N; i++) {
            if (D[i] != 0) { k = i; break; }
        }
        if (k == -1) break;

        assert(D[k] != 0);
        int sign = D[k] / abs(D[k]);

        ans++;

        for (int i = k; i < N && D[i] * sign > 0; i++) {
            D[i] -= sign;
        }
    }

    cout << ans << '\n';
    return 0;
}
