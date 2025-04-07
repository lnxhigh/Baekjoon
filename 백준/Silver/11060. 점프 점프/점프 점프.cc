#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;
const int INF = 1 << 20;

int N;
int A[MAX];
int D[MAX];

int dfs(int x) {
    if (x >= N - 1) return 0;
    if (D[x] != -1) return D[x];
    
    D[x] = INF;
    for (int jump = 1; jump <= A[x]; jump++) {
        D[x] = min(D[x], dfs(x + jump) + 1);
    }
    
    return D[x];
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    memset(D, -1, sizeof(D));

    int ans = dfs(0);
    if (ans >= INF) ans = -1;
    cout << ans << '\n';

    return 0;
}
