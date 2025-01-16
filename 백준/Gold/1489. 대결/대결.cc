#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 51;

int N;
int A[MAX], B[MAX];
int D[MAX][MAX][MAX];

int fight(int x, int y) {
    if (x > y) return 2;
    else if (x == y) return 1;
    return 0;
}

int dfs(int i, int j, int len) {
    if (D[i][j][len] != -1) return D[i][j][len];
    if (len == 0) return D[i][j][len] = 0;

    // match i to j
    int win = dfs(i + 1, j + 1, len - 1) + fight(A[i], B[j]);
    
    // match i to j + len - 1
    int lose = dfs(i + 1, j, len - 1) + fight(A[i], B[j + len - 1]);

    return D[i][j][len] = max(win, lose);
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    sort(A, A + N); sort(B, B + N);

    memset(D, -1, sizeof(D));
    int ans = dfs(0, 0, N);
    cout << ans << '\n';
    return 0;
}
