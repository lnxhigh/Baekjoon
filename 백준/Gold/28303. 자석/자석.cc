#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 19;

int N, K;
int A[MAX], B[MAX];

int main() {
    FastIO
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        A[i] = x + i * K;
        B[i] = x - i * K;
    }

    int x = 0;
    int ans = -0x7FFFFFFF;

    x = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        ans = max(ans, A[i] - x);
        x = min(x, A[i]);
    }

    x = B[0];
    for (int i = 1; i < N; i++) {
        ans = max(ans, B[i] - x);
        x = min(x, B[i]);
    }
    
    cout << ans << '\n';
    return 0;
}
