#include <string>
#include <vector>

using namespace std;

const int MAXN = 300005;
vector<int> sales;
vector<int> tree[MAXN];

int dp[MAXN][2];
bool chk[MAXN][2];

int dfs(int x, bool flag, const vector<int> &weights) {
    if (chk[x][flag]) return dp[x][flag];
    chk[x][flag] = true;
    
    int res = 2147483647, sum = 0;
    for (int nxt : tree[x]) {
        sum += min(dfs(nxt, true, weights), dfs(nxt, false, weights));
    }
    
    if (flag) return dp[x][flag] = weights[x] + sum;
    
    if (tree[x].empty()) {
        return dp[x][flag] = 0;
    }
    
    for (int nxt : tree[x]) {
        int x = min(dfs(nxt, true, weights), dfs(nxt, false, weights));
        int tmp = (sum - x) + dfs(nxt, true, weights);
        res = min(res, tmp);
    }

    return dp[x][flag] = res;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    for (vector<int> link : links) {
        int parent = link[0];
        int child = link[1];
        parent--, child--;
        
        tree[parent].push_back(child);
    }
    
    int x = dfs(0, true, sales);
    int y = dfs(0, false, sales);
    int answer = min(x, y);
    return answer;
}
