#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 201;

int T;
int D[MAX][MAX];
string A, B, S;

int dfs(int i, int j) {
    if (i == -1) return B.substr(0, j + 1) == S.substr(0, j + 1);
    if (j == -1) return A.substr(0, i + 1) == S.substr(0, i + 1);
    if (D[i][j] != -1) return D[i][j];

    int x = 0;
    if (A[i] == S[i + j + 1]) x += dfs(i - 1, j);
    if (B[j] == S[i + j + 1]) x += dfs(i, j - 1);
    return D[i][j] = x ? 1 : 0;
}

int main() {
    FastIO
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> A >> B >> S;
        memset(D, -1, sizeof(D));
        int M = A.size(), N = B.size();
        bool flag = dfs(M - 1, N - 1);
        string ans = flag ? "yes" : "no";
        cout << "Data set " << t << ": " << ans << '\n';
    }

    return 0;
}
