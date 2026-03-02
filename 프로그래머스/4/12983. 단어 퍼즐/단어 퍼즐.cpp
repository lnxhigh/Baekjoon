#include <bits/stdc++.h>

using namespace std;
const int MAX = 20001;

int dp[MAX];
bool chk[MAX];

int dfs(int idx, const unordered_set<string> &strs, const string &t) {
    if (idx == t.size()) return 0;
    if (chk[idx]) return dp[idx];
    
    int res = t.size() + 1;
    
    for (int len = 1; len <= 5 && idx + len <= t.size(); len++) {
        string s = t.substr(idx, len);
        bool match = (strs.find(s) != strs.end());
        if (!match) continue;
        
        int tmp = dfs(idx + len, strs, t);
        res = min(res, tmp + 1);
    }
    
    chk[idx] = true;
    return dp[idx] = res;
}

int solution(vector<string> strs, string t)
{
    unordered_set<string> s;
    for (const string &str : strs) s.insert(str);
    
    int x = dfs(0, s, t);
    int ans = (x <= t.size()) ? x : -1;
    return ans;
}
