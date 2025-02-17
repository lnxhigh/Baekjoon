#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int N, M, K; cin >> N >> M >> K;

        vector<int> A(N << 1);
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            A[i] = A[N + i] = x;
        }

        int sum = 0;
        for (int i = 0; i < M; i++) {
            sum += A[i];
        }

        int cnt = 0;

        if (M == N) {
            if (sum < K) cnt++;
            cout << cnt << '\n';
        }
        else {
            for (int i = 0; i < N; i++) {
                if (sum < K) cnt++;
                sum += A[M + i] - A[i];
            }
            cout << cnt << '\n';
        }
    }

    return 0;
}
