#include <bits/stdc++.h>

using namespace std;
const int MAX = 360001;
int cnt[MAX];
int s[MAX], e[MAX];

// HH:MM:SS
int parse(string time) {
    int hh = stoi(time.substr(0, 2));
    int mm = stoi(time.substr(3, 2));
    int ss = stoi(time.substr(6, 2));
    return hh * 3600 + mm * 60 + ss;
}

string convert(int t) {
    int h = t / 3600;
    int m = (t % 3600) / 60;
    int s = (t % 3600) % 60;
    
    string hh = (h < 10) ? "0" + to_string(h) : to_string(h);
    string mm = (m < 10) ? "0" + to_string(m) : to_string(m);
    string ss = (s < 10) ? "0" + to_string(s) : to_string(s);
    
    return hh + ":" + mm + ":" + ss;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    for (const string &log : logs) {
        int from = parse(log.substr(0, 8));
        int to = parse(log.substr(9, 8));
        s[from]++, e[to]++;
    }
    
    int x = 0;
    for (int t = 0; t < MAX; t++) {
        x += s[t] - e[t];
        cnt[t] = x;
    }
    
    long long sum = 0, maxsum = 0;
    int play = parse(play_time);
    int adv = parse(adv_time);
    
    int ans = 0;
    for (int t = 0; t < adv; t++) sum += cnt[t];
    maxsum = sum;
    
    for (int t = 0; t < play - adv; t++) {
        sum += cnt[t + adv];
        sum -= cnt[t];
        
        if (sum > maxsum) ans = t + 1, maxsum = sum;
    }

    return convert(ans);
}
