#include <bits/stdc++.h>

using namespace std;
const int MAX = 16;

int dp[MAX][1 << MAX];
bool chk[MAX][1 << MAX];

int f(int bits,
    const vector<vector<int>> &cost, 
    const vector<vector<int>> &hint
) {
    int n = cost.size();
    vector<int> counts(n);
    
    for (int i = 0; i < n; i++) {
        bool on = (bits >> i) & 1;
        if (!on) continue;
        
        const vector<int> &vec = hint[i];
        int k = vec.size();
        
        for (int x = 1; x < k; x++) {
            int num = vec[x] - 1;
            counts[num]++;
        }
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int count = min(counts[i], n - 1);
        sum += cost[i][count];
    }
    
    return sum;
}

int dfs(int idx, int bits,
    const vector<vector<int>> &cost, 
    const vector<vector<int>> &hint
) { 
    int n = cost.size();
    if (idx == n) return f(bits, cost, hint);
    else if (chk[idx][bits]) return dp[idx][bits];
    
    int x = dfs(idx + 1, bits, cost, hint);
    int y = dfs(idx + 1, bits | (1 << idx), cost, hint) + hint[idx][0];
    
    chk[idx][bits] = true;
    return dp[idx][bits] = min(x, y);
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    hint.push_back({ 0 });
    return dfs(0, 0, cost, hint);
}
