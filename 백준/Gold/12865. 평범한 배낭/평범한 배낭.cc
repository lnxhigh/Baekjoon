#include <bits/stdc++.h>
using namespace std;

int N, K;
const int N_MAX = 101;
const int K_MAX = 100001;

int W[N_MAX], V[N_MAX];
int D[K_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    // 메모리 절약 => 역순으로 반복하면 되는 것 같다 ...?!
    for (int i = 1; i <= N; i++) {
        for (int w = K; w >= W[i]; w--) {
            D[w] = max(D[w], D[w-W[i]] + V[i]);
        }
    }

    cout << D[K] << '\n';
    return 0;
}
