#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 4;
int D[MAX][MAX];

int main() {
    for (int i = 1; i < MAX; i++) {
        D[0][i] = i;
    }

    for (int h = 1; h < MAX; h++) {
        for (int i = 1; i < MAX; i++) {
            D[h][i] = D[h][i-1] + D[h-1][i];
        }
    }

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        cout << D[n][k] << '\n';
    }
    return 0;
}
