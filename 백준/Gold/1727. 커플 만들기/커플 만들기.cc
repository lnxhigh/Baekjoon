#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int N, M;
int A[MAX], B[MAX];
int D[MAX][MAX];

int dfs(int i, int j) {
    if (i < 0 || j < 0) return 0;
    else if (D[i][j] != -1) return D[i][j];
    
    int ret = dfs(i - 1, j - 1) + abs(A[i] - B[j]);
    if (i > j) ret = min(ret, dfs(i - 1, j));
    else if (i < j) ret = min(ret, dfs(i, j - 1));
    return D[i][j] = ret;
}

int main() {
    FastIO
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(A, A + N), sort(B, B + M);

    memset(D, -1, sizeof(D));
    int ans = dfs(N - 1, M - 1);
    cout << ans << '\n';
    return 0;
}
