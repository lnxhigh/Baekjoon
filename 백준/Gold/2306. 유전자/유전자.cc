#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 9;

string DNA;
int D[MAX][MAX];

int dfs(int i, int j) {
    if (D[i][j] != -1) return D[i][j];
    else if (j <= i) return D[i][j] = 0;
    
    int ret = 0;
    int lo = i, hi = j;

    while (lo < j && DNA[lo] != 'a') lo++;
    while (hi > i && DNA[hi] != 't') hi--;
    if (lo < hi) ret = max(ret, dfs(lo + 1, hi - 1) + 2);

    lo = i, hi = j;
    while (lo < j && DNA[lo] != 'g') lo++;
    while (hi > i && DNA[hi] != 'c') hi--;
    if (lo < hi) ret = max(ret, dfs(lo + 1, hi - 1) + 2);

    for (int k = i; k < j; k++) {
        ret = max(ret, dfs(i, k) + dfs(k + 1, j));
    }

    return D[i][j] = ret;
}

int main() {
    FastIO
    cin >> DNA;
    int L = DNA.size();

    memset(D, -1, sizeof(D));
    int ans = dfs(0, L - 1);
    cout << ans << '\n';
    return 0;
}
