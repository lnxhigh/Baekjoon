#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MAX = 10005;
const int64 MOD = 987654321;

int64 N;
int64 D[MAX];

int64 dfs(int64 n) {
    if (D[n] != -1) return D[n];
    else if (n == 0) return D[n] = 1;
    
    int64 cnt = 0;
    for (int64 i = 1; i < n; i += 2) {
        cnt += dfs(n - i - 1) * dfs(i - 1);
        cnt %= MOD;
    }

    return D[n] = cnt;
}

int main() {
    cin >> N;
    memset(D, -1, sizeof(D));
    cout << dfs(N) << '\n';
    return 0;
}
