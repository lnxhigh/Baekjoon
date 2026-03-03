#include <bits/stdc++.h>

using namespace std;

int arr[8][32];

int f(int n, vector<pair<int,int>> &reqs) {
    int t = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (auto req : reqs) {
        auto [a, b] = req;
        while (!pq.empty() && pq.top() <= a) pq.pop();
        
        int cnt = pq.size();
        int end = a + b;
        
        if (cnt >= n) {
            int wait = pq.top() - a;
            pq.pop();
            t += wait, end += wait;
        }
        
        pq.push(end);
    }
    
    return t;
}

void dfs(int k, int n, vector<int> &vec, int &result) {
    if (vec.size() == k) {
        int sum = 0;
        for (int x : vec) sum += x;
        if (sum != n) return;
        
        int t = 0;
        for (int i = 0; i < k; i++) {
            int idx = i + 1;
            int num = vec[i];
            t += arr[idx][num];
        }
        
        result = (result != -1) ? min(result, t) : t;
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        vec.push_back(i);
        dfs(k, n, vec, result);
        vec.pop_back();
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    for (int i = 1; i <= k; i++) {
        vector<pair<int,int>> vec;
        for (auto req : reqs) {
            int a = req[0], b = req[1], c = req[2];
            if (c != i) continue;
            vec.push_back({ a, b });
        }
        
        for (int x = 1; x <= n; x++) {
            arr[i][x] = f(x, vec);
        }
    }
    
    int ans = -1;
    vector<int> nums;
    dfs(k, n, nums, ans);
    
    return ans;
}
