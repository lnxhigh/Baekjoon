#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    long long M; cin >> M;
    
    vector<long long> P(N);
    for (auto &x : P) cin >> x;

    long long res = 0;

    for (int k = 1; k <= N; k++) {
        vector<bool> V(N);
        for (int i = 1; i <= k; i++) V[N-i] = true; 

        long long total = 0;
        
        do {
            long long X = 1;
            for (int i = 0; i < N; i++) {
                if (V[i]) X *= P[i];
            }
            total += M / X;
        } while (next_permutation(V.begin(), V.end()));

        if (k % 2 == 0) total *= -1;
        res += total;
    }

    cout << res << '\n';
    return 0;
}
