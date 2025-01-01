#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std; 

int solve(int N, int A, int B) {
    vector<tuple<int,int,int,int>> X(N);

    for (int i = 0; i < N; i++) {
        int k, u, v; cin >> k >> u >> v;
        X[i] = { -abs(u - v), k, u, v };
    }
    sort(X.begin(), X.end());

    int ret = 0;
    for (auto [_, k, u, v] : X) {
        int a = (u < v) ? min(A, k) : k - min(B, k);
        int b = (u < v) ? k - min(A, k) : min(B, k);

        A -= a, B -= b;
        ret += u * a + v * b;
    }

    return ret;
}

int main() {
    FastIO
    while (true) {
        int N, A, B;
        cin >> N >> A >> B;
        if (!N) break;
        int ans = solve(N, A, B);
        cout << ans << '\n';
    }

    return 0;
}
