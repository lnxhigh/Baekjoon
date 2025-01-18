#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int N;
pair<int,int> A[MAX];

int solve() {
    int X = 0;
    int diff = 1 << 30;
    
    for (int i = 0; i < N; i++) {
        auto [S, T] = A[i];
        if (X + T > S) return -1;
        
        X += T;
        diff = min(diff, S - X);
    }

    return diff;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        int T, S; cin >> T >> S;
        A[i] = { S, T };
    }
    sort(A, A + N);

    int ans = solve();
    cout << ans << '\n';
    return 0;
}
