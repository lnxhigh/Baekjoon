#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N, M;
string guess, answer;
vector<vector<int>> D;

bool match(int i, int j) {
    char x = guess[i], y = answer[j];
    if (x == 'i') return y == 'i' || y == 'j' || y == 'l';
    else if (x == 'v') return y == 'v' || y == 'w';
    return x == y;
}

int dfs(int i, int j) {
    if (i == -1 || j == -1) return i + j + 2;
    else if (D[i][j] != -1) return D[i][j];
    
    if (match(i, j)) return D[i][j] = dfs(i - 1, j - 1);

    int ins = dfs(i, j - 1), del = dfs(i - 1, j), rep = dfs(i - 1, j - 1);
    int ret = min({ ins, del, rep }) + 1;
    return D[i][j] = ret;
}

int main() {
    FastIO
    cin >> N >> M;
    cin >> guess >> answer;

    D = vector<vector<int>>(N, vector<int>(M, -1));
    int ans = dfs(N - 1, M - 1);
    cout << ans << '\n';
    return 0;
}
