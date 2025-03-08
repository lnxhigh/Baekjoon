#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 101;

int N, A, B;
int P[MAX], Q[MAX], R[MAX], S[MAX];
int D[MAX][MAX][MAX][2];

int dfs(int day, int a, int b, int f) {
    if (day == N) return 0;

    int& ret = D[day][a][b][f];
    if (ret) return ret;

    ret = dfs(day + 1, a, b - 1, 0) + max(P[day], Q[day]);
    if (day + b == N) return ret;
    
    if (f < 1) ret = max(ret, dfs(day + 1, a, b, f + 1) + R[day]);
    if (a > 0) ret = max(ret, dfs(day + 1, a - 1, b, 0) + S[day]);

    return ret;
}

int main() {
    FastIO
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> Q[i] >> R[i] >> S[i];
    }
    
    int ans = dfs(0, A, B, 0);
    cout << ans << '\n';
    return 0;
}
