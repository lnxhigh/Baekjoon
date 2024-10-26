#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 300;
int A[MAX];
int D[MAX][2];

int dfs(int n, int k) {
    if (n < 0 || k < 0) return 0;
    if (D[n][k]) return D[n][k];

    int one = dfs(n - 1, k - 1);
    int two = dfs(n - 2, 1);
    return D[n][k] = max(one, two) + A[n];
}

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cout << dfs(N - 1, 1) << '\n';
    return 0;  
}
