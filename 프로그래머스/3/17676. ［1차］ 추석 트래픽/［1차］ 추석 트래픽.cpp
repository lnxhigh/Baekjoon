#include <bits/stdc++.h>

using namespace std;
using range = pair<int,int>;

pair<int,int> f(string line) {
    string s = line.substr(11, 12);
    string t = line.substr(24);
    
    // S - hh:mm:ss.sss
    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 2));
    int ss = stoi(s.substr(6, 2));
    int sss = stoi(s.substr(9, 3));
    
    int end = hh * 60 * 60 * 1000 + 60 * 1000 * mm + 1000 * ss + sss;
    
    // T
    t.pop_back();
    
    int duration = 0;
    int index = t.find('.');
    
    if (index == string::npos) {
        duration = stoi(t) * 1000;
    } else {
        string x = t.substr(0, index);
        string y = t.substr(index + 1);
        while (y.size() < 3) y.push_back('0');
        duration = stoi(x) * 1000 + stoi(y);
    }
    
    int start = end - duration + 1;
    
    return { start, end };
}

int solution(vector<string> lines) {
    vector<range> v;
    priority_queue<range, vector<range>, greater<range>> pq;
    vector<int> ends;
    
    int ans = 0;
    int n = lines.size();
    int idx = 0;
    
    for (string line : lines) {
        auto [start, end] = f(line);
        v.push_back({ start, end });
        ends.push_back(end);
    }
    
    sort(v.begin(), v.end());
    sort(ends.begin(), ends.end());
    
    // Sweeping
    
    for (int t : ends) {
        while (idx < n) {
            auto [start, end] = v[idx];
            if (start <= t + 999) pq.push({ end, start }), idx++;
            else break;
        }
        
        while (!pq.empty()) {
            auto [end, start] = pq.top();
            if (end < t) pq.pop();
            else break;
        }
        
        int size = pq.size();
        ans = max(ans, size);
    }
    
    return ans;
}
