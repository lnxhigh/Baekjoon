#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N);
        for (int &x : A) cin >> x;

        vector<int> D; D.reserve(N * N / 2);
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int diff = abs(A[i] - A[j]);
                if (diff != 0) D.push_back(diff);
            }
        }

        if (D.empty()) {
            cout << "INFINITY" << '\n';
            continue;
        }

        int x = D[0];
        for (int i : D) x = gcd(x, i);
        cout << x << '\n';
    }
    
    return 0;
}
