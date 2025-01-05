#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 100005;

int64 N, S;
int64 C[MAX];
int64 L[MAX], R[MAX];

int main() {
    FastIO
    cin >> N >> S;
    for (int64 i = 0; i < N; i++) {
        cin >> C[i];
    }

    L[0] = C[0], R[N - 1] = C[N - 1];
    for (int64 i = 1; i < N; i++) {
        L[i] = min(L[i - 1], C[i]);
        R[N - 1 - i] = min(R[N - i], C[N - 1 - i]);
    }

    int64 ans = L[N - 1];
    for (int64 k = 0; k < N - 1; k++) {
        int64 x = L[k] + S * (N - 1 - k); // Left
        int64 y = R[k + 1] - S * (k + 1); // Right
        
        int64 val = min(x, y);
        ans = max(ans, val);
    }

    cout << ans << '\n';
    return 0;
}
