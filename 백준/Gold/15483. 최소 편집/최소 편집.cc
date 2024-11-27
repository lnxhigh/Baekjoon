#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 10;

string from, to;
int D[MAX][MAX];

int dfs(int i, int j) {
    if (i == -1 || j == -1) return i + j + 2;
    else if (D[i][j] != -1) return D[i][j];
    
    if (from[i] == to[j]) return D[i][j] = dfs(i - 1, j - 1);

    int ins = dfs(i, j - 1), del = dfs(i - 1, j), rep = dfs(i - 1, j - 1);
    int ret = min({ ins, del, rep }) + 1;
    return D[i][j] = ret;
}

int main() {
    memset(D, -1, sizeof(D));
    cin >> from >> to;
    
    int N = from.size(), M = to.size();
    int ans = dfs(N - 1, M - 1);
    cout << ans << '\n';
    return 0;
}
