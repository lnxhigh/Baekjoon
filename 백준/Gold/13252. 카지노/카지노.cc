#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 1 << 6;

int64 N, M, K;
map<int64,double> D[MAX];

double dfs(int64 n, int64 k) {
    if (k == 0) return n > 0;
    else if (n <= 0 || M == 1) return 0;
    if (D[k][n]) return D[k][n];

    int64 x = n / M;
    double p = (double) (n % M) / (double) M;
    return D[k][n] = p * dfs(n - x - 1, k - 1) + (1 - p) * dfs(n - x, k - 1);
}

int main() {
    FastIO
    cin >> N >> M >> K;
    cout << setprecision(16);
    cout << dfs(N, K) << '\n';
    return 0;
}
