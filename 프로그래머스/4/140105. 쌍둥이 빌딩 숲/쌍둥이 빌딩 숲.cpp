#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll M = 1000000007LL;
const int MAX = 128;

int cache[MAX][MAX];

int dfs(int n, int k) {
    if (n == k) return 1;
    else if (n < k || k == 0) return 0;
    if (cache[n][k]) return cache[n][k];
    
    int x = dfs(n - 1, k - 1) % M;
    int y = (long long) dfs(n - 1, k) * (2 * n - 2) % M;
    return cache[n][k] = (x + y) % M;
}

int solution(int n, int k) {
    return dfs(n, k);
}
