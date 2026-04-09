#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    int n = target.size();
    vector<vector<int>> tree(n);
    
    vector<int> next(n);
    vector<int> where;
    vector<int> counts(n);
    
    vector<tuple<int,int,int>> triplets(n);
    vector<bool> chk(n);
    
    int m = 0;
    
    for (const vector<int> &edge : edges) {
        int x = edge[0] - 1;
        int y = edge[1] - 1;
        tree[x].push_back(y);
    }
    
    for (int x = 0; x < n; x++) {
        if (not tree[x].empty() and target[x] > 0) {
            return { -1 };
        }
        if (not tree[x].empty()) {
            sort(tree[x].begin(), tree[x].end());
        }
        if (tree[x].empty() and target[x] == 0) {
            triplets[x] = { 0, 0, 0 };
            chk[x] = true;
        }   
    }
    
    for (int sum : target) {
        m = max(m, sum);
    }
    
    for (int t = 0; t < m * n; t++) {
        // 숫자를 떨어뜨린다
        
        int x = 0;
        while (!tree[x].empty()) {
            int idx = next[x];
            next[x] = (idx + 1) % tree[x].size();
            x = tree[x][idx];
        }
        
        where.push_back(x);
        counts[x]++;
        
        // 숫자의 합을 같게 만든다
        
        int cnt = counts[x];
        int sum = target[x];
        
        chk[x] = false; // 초기화
        
        for (int a = 0; a <= min(cnt, sum); a++) {
            int b = -2 * a + 3 * cnt - sum;
            int c = a - 2 * cnt + sum;
            
            if (a + b + c != cnt or a + 2 * b + 3 * c != sum) continue;
            if (b < 0 or c < 0) continue;
            
            triplets[x] = { a, b, c };
            chk[x] = true;
        }
        
        // 해 구성 가능성 체크
        
        bool flag = true;
        
        for (int i = 0; i < n and flag; i++) {
            if (not tree[i].empty()) continue;
            if (not chk[i]) flag = false;
        }
        
        if (!flag) continue;
        
        // 해 구성
        
        vector<int> ans;
        
        for (int i : where) {
            auto [a, b, c] = triplets[i];
            
            int num = 0;
            
            if (a > 0) num = 1, a--;
            else if (b > 0) num = 2, b--;
            else if (c > 0) num = 3, c--;

            ans.push_back(num);
            triplets[i] = { a, b, c };
        }
        
        return ans;
    }
    
    return { -1 };
}
