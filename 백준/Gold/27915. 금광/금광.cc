#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100005;

int N;
int P[MAX];
int D[MAX];

int dfs(int x) {
    if (x == 0) return 0;
    else if (D[x]) return D[x];
    return D[x] = dfs(P[x]) + 1;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> P[i]; P[i]--;
    }

    int odd = 0, even = 0;
    for (int i = 0; i < N; i++) {
        if (dfs(i) & 1) odd++;
        else even++;
    }

    int ans = min(odd, even) + abs(odd - even);
    cout << ans << '\n';
    return 0;
}
