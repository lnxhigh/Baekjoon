#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> D(N+1);
    D[0] = 1, D[1] = 0;

    for (int i = 2; i <= N; i++) {
        for (int k = 2; k <= i; k += 2) {
            D[i] += D[i-k];
        }
        D[i] = (D[i] << 1) + D[i-2];
    }

    cout << D[N] << '\n';
    return 0;
}
