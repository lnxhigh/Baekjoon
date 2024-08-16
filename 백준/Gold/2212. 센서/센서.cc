#include <bits/stdc++.h>
#define For(i, N) for (int i = 0; i < N; i++)
using namespace std;

int N, K, Y;
const int MAX = 1 << 14;
const int INF = 1 << 21;
int X[MAX], D[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    For(i, N) cin >> X[i];
    sort(X, X + N);
    For(i, N-1) D[i] = X[i+1] - X[i];
    sort(D, D + N-1);
    For(i, N-K) Y += D[i];
    cout << Y << '\n';
    return 0;
}
