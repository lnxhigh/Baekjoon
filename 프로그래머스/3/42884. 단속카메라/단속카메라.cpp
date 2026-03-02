#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> routes) {
    vector<pair<int,int>> vec;
    priority_queue<pair<int,int>> pq;
    vector<bool> chk(routes.size());
    
    for (int i = 0; i < routes.size(); i++) {
        vector<int> route = routes[i];
        int start = route[0];
        int end = route[1];
        
        vec.push_back({ end, i });
        pq.push({ -start, i });
    }
    
    sort(vec.begin(), vec.end());
    
    int cnt = 0;
    
    for (int i = 0; i < vec.size(); i++) {
        auto [end, idx] = vec[i];
        if (chk[idx]) continue;
        
        cnt++;
        
        while (!pq.empty()) {
            auto [start, topIdx] = pq.top();
            start = -start;
            if (start > end) break;
            
            pq.pop();
            chk[topIdx] = true;
        }
    }
    
    return cnt;
}
