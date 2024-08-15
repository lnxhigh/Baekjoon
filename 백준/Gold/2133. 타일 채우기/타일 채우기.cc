#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 1 << 5;
int D[MAX];

int main() {
    cin >> N;
    D[0] = 1; D[1] = 0;
    
    for (int i = 2; i <= N; i++) {
        D[i] += D[i-2];
        for (int k = 2; k <= i; k += 2) {
            D[i] += D[i-k] * 2;
        }
    }

    cout << D[N] << '\n';
    return 0;
}
