#include <bits/stdc++.h>

using namespace std;
const int INF = 1 << 20;

int table[3][3] = {
    {  1, 1, 1 },
    {  5, 1, 1 },
    { 25, 5, 1 },
};

int dp[6][6][6][51];
bool chk[6][6][6][51];

int dfs(int x, int y, int z, int idx, const vector<int> &minerals) {
    int n = minerals.size();
    if (idx >= n) return 0;
    if (x == 0 and y == 0 and z == 0) return 0;
    
    if (chk[x][y][z][idx]) return dp[x][y][z][idx];
    
    int ret = INF;
    
    if (x > 0) {
        int sum = 0, pick = 0;
        for (int i = idx; i < idx + 5 and i < n; i++) {
            int mineral = minerals[i];
            sum += table[pick][mineral];
        }
        ret = min(ret, sum + dfs(x - 1, y, z, min(idx + 5, n), minerals));
    }
    if (y > 0) {
        int sum = 0, pick = 1;
        for (int i = idx; i < idx + 5 and i < n; i++) {
            int mineral = minerals[i];
            sum += table[pick][mineral];
        }
        ret = min(ret, sum + dfs(x, y - 1, z, min(idx + 5, n), minerals));
    }
    if (z > 0) {
        int sum = 0, pick = 2;
        for (int i = idx; i < idx + 5 and i < n; i++) {
            int mineral = minerals[i];
            sum += table[pick][mineral];
        }
        ret = min(ret, sum + dfs(x, y, z - 1, min(idx + 5, n), minerals));
    }
    
    chk[x][y][z][idx] = true;
    return dp[x][y][z][idx] = ret;
}

int solution(vector<int> picks, vector<string> minerals) {
    vector<int> nums;
    for (string mineral : minerals) {
        int num = -1;
        if (mineral == "diamond") num = 0;
        else if (mineral == "iron") num = 1;
        else if (mineral == "stone") num = 2;
        
        if (num < 0) continue;
        nums.push_back(num);
    }
    
    int diamond = picks[0];
    int iron = picks[1];
    int stone = picks[2];
    
    return dfs(diamond, iron, stone, 0, nums);
}
