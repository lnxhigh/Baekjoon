#include <bits/stdc++.h>

using namespace std;
const int MAX = 10005;

int n;
int root = 0;
vector<int> nums;
pair<int,int> tree[MAX];
int par[MAX];

void dfs(int i, int m, vector<int> &sums, int& groups) {
    auto [l, r] = tree[i];
    if (l != -1) dfs(l, m, sums, groups);
    if (r != -1) dfs(r, m, sums, groups);
    
    sums[i] += nums[i];
    
    if (l == -1 && r == -1) return;
    
    if (l != -1 && r != -1) {
        int x = min(sums[l], sums[r]);
        int y = max(sums[l], sums[r]);
        
        if (sums[i] + x <= m) {
            sums[i] += x, groups--;
        }
        if (sums[i] + y <= m) {
            sums[i] += y, groups--;
        }
        
        return;
    }
    
    int c = (l != -1) ? l : r;
    int x = sums[c];
    
    if (sums[i] + x <= m) {
        sums[i] += x, groups--;
    }
}

bool check(int m, int k) {
    vector<int> sums(n);
    int groups = n;
    dfs(root, m, sums, groups);
    
    return groups <= k;
}

int solution(int k, vector<int> _nums, vector<vector<int>> links) {
    // Init
    n = _nums.size();
    nums = _nums;
    fill(par, par + MAX, -1);
    
    for (int i = 0; i < n; i++) {
        vector<int> &link = links[i];
        int x = link[0], y = link[1];
        tree[i] = { x, y };
        par[x] = i, par[y] = i;
    }
    
    // Compute root
    for (int i = 0; i < n; i++) {
        if (par[i] == -1) {
            root = i;
            break;
        }
    }
    
    // Parametric search
    int ans = 0;
    int low = *max_element(_nums.begin(), _nums.end());
    int high = 10000 * 10000;
    
    while (low <= high) {
        int mid = low + high >> 1;
        
        if (check(mid, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return ans;
}
