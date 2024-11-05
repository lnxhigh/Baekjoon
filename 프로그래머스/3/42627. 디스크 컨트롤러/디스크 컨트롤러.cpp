#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> jobs) {
    const int N = jobs.size();
    priority_queue<pair<int,int>> pq;
    sort(jobs.begin(), jobs.end());
    
    vector<vector<int>> hasWork(1 << 10);
    for (int i = 0; i < N; i++) {
        hasWork[jobs[i][0]].push_back(i);
    }
    
    int t = 0;
    int cnt = 0;
    int answer = 0;
    
    while (cnt < N) {
        if (!pq.empty()) {
            auto [len, work] = pq.top();
            len = -len;
            pq.pop();
            cnt++;
            
            while (len--) {
                if (t <= 1000 && !hasWork[t].empty()) {
                    for (int work : hasWork[t]) {
                        pq.push({ -jobs[work][1], work });
                    }
                }
                t++;
            }
            
            answer += t - 1 - jobs[work][0];
        }
        else {
            if (t <= 1000 && !hasWork[t].empty()) {
                for (int work : hasWork[t]) {
                    pq.push({ -jobs[work][1], work });
                }
            }
            t++;
        }   
    }
    
    answer /= N;
    return answer;
}
