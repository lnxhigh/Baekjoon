#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const int MAX = 1 << 10;
int P[MAX], D[MAX];

int main() {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) cin >> P[i];

    fill(D + 1, D + MAX, INF);
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= i; k++) {
            D[i] = min(D[i], D[i-k] + P[k]);
        }
    }

    cout << D[N] << '\n';
    return 0;
}
