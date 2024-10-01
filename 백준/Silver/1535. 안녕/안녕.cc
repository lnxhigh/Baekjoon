#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> W(N), V(N);
    for (int &w : W) cin >> w;
    for (int &v : V) cin >> v;

    const int H = 100;    
    vector<int> D(H);
    for (int i = 0; i < N; i++) {
        for (int k = H - 1; k >= W[i]; k--) {
            D[k] = max(D[k], D[k - W[i]] + V[i]);
        }
    }

    cout << D[H-1] << '\n';
    return 0;
}
