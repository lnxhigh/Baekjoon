#include <bits/stdc++.h>
using namespace std;

int L, N, M;
bool D[41][128][128];
bool vis[41][128][128];

bool dfs(int i, int n, int m, const vector<vector<int>> &info, int &ans) {
    if (i == L) {
        if (ans == -1) ans = n;
        else ans = min(ans, n);
        return true;
    }
    
    if (vis[i][n][m]) {
        return D[i][n][m];
    }
    
    bool chk = false;
    if (n + info[i][0] < N) chk |= dfs(i + 1, n + info[i][0], m, info, ans);
    if (m + info[i][1] < M) chk |= dfs(i + 1, n, m + info[i][1], info, ans);
    
    vis[i][n][m] = true;
    return D[i][n][m] = chk;
}

int solution(vector<vector<int>> info, int n, int m) {
    int answer = -1;
    
    L = info.size();
    N = n, M = m;
    
    dfs(0, 0, 0, info, answer);
    return answer;
}
