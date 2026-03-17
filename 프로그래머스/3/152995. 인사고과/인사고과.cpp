#include <bits/stdc++.h>

using namespace std;
const int MAX = 100001;

vector<int> vec[MAX];

int solution(vector<vector<int>> scores) {
    priority_queue<pair<int,int>> pq;
    int a = scores[0][0];
    int b = scores[0][1];
    
    for (const vector<int> &score : scores) {
        int x = score[0];
        int y = score[1];
        vec[x].push_back(y);
    }
    
    for (int x = 0; x < MAX; x++) {
        if (vec[x].empty()) continue;
        sort(vec[x].begin(), vec[x].end());
        
        int m = *vec[x].rbegin();
        while (!pq.empty() && -pq.top().first < m) pq.pop();
        for (int y : vec[x]) pq.push({ -y, -x });
    }
    
    int cnt = 0;
    bool chk = false;
    
    while (!pq.empty()) {
        auto [y, x] = pq.top();
        x = -x, y = -y;
        pq.pop();
        
        cnt += (x + y) > (a + b);
        chk |= (x == a) && (y == b);
    }
    
    if (!chk) return -1;
    return ++cnt;
}
