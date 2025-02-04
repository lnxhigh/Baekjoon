#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 2501;

int N, K;
double P[MAX];

bool V[MAX][11];
double D[MAX][11];

double dfs(int n, int k) {
    if (k == 0) return 0;
    else if (V[n][k]) return D[n][k];

    double ret = 0, last = 0;
    double x = 0;
    
    for (int i = n; i >= k; i--) {
        x = (1.0 - P[i]) * (x + 1);
        double p = dfs(i - 1, k - 1) + x;
        ret = max(ret, p);
        last = p;
    }

    V[n][k] = true;
    return D[n][k] = (k > 1) ? ret : last;
}

int main() {
    FastIO
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    
    double ans = dfs(N, K);
    cout << setprecision(16);
    cout << ans << '\n';
    return 0;
}
