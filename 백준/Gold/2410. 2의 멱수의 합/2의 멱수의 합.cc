#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, K;
const int MAX = 1 << 20;
const int DIV = 1000000000;
int D[MAX];

int main() {
    cin >> K;
    for (int i = 0; i < 20; i++) {
        if (K & (1 << i)) N = i;
    }

    vector<int> C(++N);
    for (int i = 0; i < N; i++) {
        C[i] = 1 << i;
    }
    
    D[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int k = C[i]; k <= K; k++) {
            D[k] += D[k - C[i]];
            D[k] %= DIV;
        }
    }

    cout << D[K] << '\n';
    return 0;
}
