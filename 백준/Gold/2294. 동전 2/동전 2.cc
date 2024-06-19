#include <bits/stdc++.h>
using namespace std;

int N, K;
const int N_MAX = 101, K_MAX = 10001;
int V[N_MAX], D[K_MAX];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) { 
        cin >> V[i]; 
    }
    
    fill(D + 1, D + K_MAX, K_MAX);
    for (int i = 0; i < N; i++) {
        for (int k = V[i]; k <= K; k++) {
            D[k] = min(D[k], D[k - V[i]] + 1);
        }
    }

    int res = (D[K] < K_MAX) ? D[K] : -1;
    cout << res << '\n';
    return 0;
}
