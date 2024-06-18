#include <bits/stdc++.h>
using namespace std;

int N, K, W, V;
int D[100001];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> W >> V;
        for (int w = K; w >= W; w--) {
            D[w] = max(D[w], D[w-W] + V);
        }
    }

    cout << D[K] << '\n';
    return 0;
}
