#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int convertToInt(string t) {
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return 60 * h + m;
}

string convertToString(int t) {
    int h = t / 60;
    int m = t % 60;
    
    string hh = to_string(h);
    if (h < 10) hh = "0" + hh;
    
    string mm = to_string(m);
    if (m < 10) mm = "0" + mm;
    
    return hh + ":" + mm;
}

bool check(int me, int n, int t, int m, const vector<int> &times) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    for (int time : times) pq.push({ time, 0 });
    pq.push({ me, 1 });
    
    int start = convertToInt("09:00");
    
    for (int i = 0; i < n; i++) {
        int bus = start + i * t;
        
        for (int k = 0; k < m; k++) {

            if (pq.empty()) break;
            auto [time, flag] = pq.top();
            
            if (time > bus) break;
            else pq.pop();
            
            if (flag) return true;
        }
    }

    return false;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string ans = "00:00";
    
    vector<int> times;
    for (string t : timetable) {
        times.push_back(convertToInt(t));    
    }
    
    int low = convertToInt("00:00");
    int high = convertToInt("23:59");
    
    while (low <= high) {
        int mid = low + high >> 1;
        bool chk = check(mid, n, t, m, times);
        
        if (chk) ans = convertToString(mid), low = mid + 1;
        else high = mid - 1;
    }
    
    return ans;
}
