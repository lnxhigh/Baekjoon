#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;
const int INF = 1 << 20;

int N;
int D[MAX];

int main() {
    FastIO
    cin >> N;

    fill(D, D + N, INF);
    D[0] = 0;
    
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        for (int j = 1; j <= x; j++) {
            if (i + j < N) D[i + j] = min(D[i + j], D[i] + 1);
        }
    }

    int ans = (D[N - 1] < INF) ? D[N - 1] : -1;
    cout << ans << '\n';
    return 0;
}
