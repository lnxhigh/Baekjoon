#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 5;

string S;
int D[MAX][MAX];

int dfs(int l, int r) {
    if (D[l][r] != -1) return D[l][r];
    else if (l == r) return D[l][r] = 1;
    else if (l >  r) return D[l][r] = 0;

    int cnt = r - l + 1;
    for (int i = l; i <= r; i++) {
        for (int j = i + 1; j <= r; j++) {
            if (S[i] == S[j]) cnt += dfs(i + 1, j - 1) + 1;
        }
    }

    return D[l][r] = cnt;
}

int main() {
    memset(D, -1, sizeof(D));
    cin >> S;

    int L = S.size();
    int ans = dfs(0, L - 1);
    cout << ans << '\n';
    return 0;
}
