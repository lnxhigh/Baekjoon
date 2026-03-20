#include <bits/stdc++.h>

using namespace std;

int f(const vector<int> &weak, const vector<int> &dist) {    
    int weak_idx = 0;
    int dist_idx = 0;
    
    while (weak_idx < weak.size() and dist_idx < dist.size()) {
        int from = weak[weak_idx];
        int to = from + dist[dist_idx];
        
        while (weak_idx < weak.size() and weak[weak_idx] <= to) weak_idx++;
        dist_idx++;
    }
    
    if (weak_idx < weak.size()) return -1;
    return dist_idx;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int ans = -1;
    
    for (int i = 0; i < weak.size(); i++) {
        vector<int> rotated(weak.size());
        for (int idx = 0; idx < rotated.size(); idx++) {
            rotated[idx] = (weak[idx] - weak[i] + n) % n;
        }
        
        sort(rotated.begin(), rotated.end());
        sort(dist.begin(), dist.end());
        
        do {
            int cnt = f(rotated, dist);
            if (cnt < 0) continue;
            ans = (ans >= 0) ? min(ans, cnt) : cnt;
        } while (next_permutation(dist.begin(), dist.end()));
    }
    
    return ans;
}
    