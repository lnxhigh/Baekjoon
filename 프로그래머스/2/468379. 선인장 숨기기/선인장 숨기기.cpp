#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    pair<int,int> ans = { 1, 1 };
    
    int low = 1, high = drops.size();
    
    while (low <= high) {
        int mid = (low + high) / 2;
        bool chk = false;
        pair<int,int> where = { 1, 1 };
        
        vector<vector<bool>> arr(m + 1, vector<bool>(n + 1));
        vector<vector<int>> sum(m + 1, vector<int>(n + 1));
        
        for (int i = 0; i < mid; i++) {
            const vector<int> &drop = drops[i];
            int x = drop[0] + 1, y = drop[1] + 1;
            arr[x][y] = true;
        }
        
        for (int x = 1; x <= m; x++) {
            for (int y = 1; y <= n; y++) {
                if (arr[x][y]) sum[x][y]++;
                sum[x][y] += sum[x - 1][y] + sum[x][y - 1] - sum[x - 1][y - 1];
            }
        }
        
        for (int x = 1; x + h - 1 <= m and not chk; x++) {
            for (int y = 1; y + w - 1 <= n and not chk; y++) {
                int cnt = sum[x + h - 1][y + w - 1];
                cnt -= sum[x + h - 1][y - 1] + sum[x - 1][y + w - 1];
                cnt += sum[x - 1][y - 1];
                
                if (cnt == 0) {
                    chk = true;
                    where = { x, y };
                }
            }
        }
        
        if (chk) {
            ans = where;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    auto [x, y] = ans;
    return { x - 1, y - 1 };
}
