#include <bits/stdc++.h>

using namespace std;
const int MAX = 201;

extern int excavate(int);

int dp[MAX][MAX];
bool chk[MAX][MAX];
int pre[MAX][MAX];

int f(int idx) {
    return excavate(idx + 1);
}

int dfs(int x, int y, const vector<int> &arr) {
    if (x > y) return 0;
    if (chk[x][y]) return dp[x][y];

    int ret = 1e9;
    int w = arr.size();
    
    for (int i = x; i <= y; i++) {
        int l = dfs(x, i - 1, arr) + arr[i];
        int r = dfs(i + 1, y, arr) + arr[i];
        if (max(l, r) >= ret) continue;
        
        ret = min(ret, max(l, r));
        pre[x][y] = i;
    }
    
    chk[x][y] = true;
    return dp[x][y] = ret;
}

int solution(vector<int> depth, int money) {
    int w = depth.size();
    int low = 0, high = w - 1;
    dfs(low, high, depth);
    
    while (low <= high) {
        int t = pre[low][high];
        int x = f(t);
        
        if (x > 0) low = t + 1;
        else if (x < 0) high = t - 1;
        else return t + 1;
    }
    
    return 0;
}
