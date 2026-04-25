#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100001;

int N, K;
int A[MAX];

int main() {
    FastIO
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> A[i];

    int x = 0;
    for (int i = 0; i < K; i++) x += A[i];

    int ans = x;
    for (int i = K; i < N; i++) {
        x += A[i] - A[i - K];
        ans = max(ans, x);
    }

    cout << ans << '\n';
    return 0;
}
