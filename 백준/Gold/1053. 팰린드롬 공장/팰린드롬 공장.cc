#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 51;

string S;
int D[MAX][MAX];

int dfs(int i, int j) {
    if (i > j) return 0;
    if (D[i][j] != -1) return D[i][j];

    if (S[i] == S[j]) return D[i][j] = dfs(i + 1, j - 1);
    int cnt = min({ dfs(i + 1, j), dfs(i, j - 1), dfs(i + 1, j - 1) });
    return D[i][j] = cnt + 1;
}

int main() {
    FastIO
    cin >> S;
    int L = S.size();

    memset(D, -1, sizeof(D));
    int ans = dfs(0, L - 1);

    for (int i = 0; i < L; i++) {
        for (int j = i + 1; j < L; j++) {
            swap(S[i], S[j]);
            memset(D, -1, sizeof(D));
            int cnt = dfs(0, L - 1);
            
            ans = min(ans, cnt + 1);
            swap(S[i], S[j]);
        }
    }
    
    cout << ans << '\n';
    return 0;
}
