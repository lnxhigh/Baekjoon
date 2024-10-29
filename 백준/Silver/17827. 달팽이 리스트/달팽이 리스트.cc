#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int N, Q, V;
    cin >> N >> Q >> V; 
    --V;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        C[i] = --x;
    }
    
    int P = N - V; 
    while (Q--) {
        int k; cin >> k;
        if (k >= V) k = V + (k - V) % P;
        cout << C[k] + 1 << '\n';
    }

    return 0;
}
