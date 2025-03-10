#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    int n = schedules.size();
    startday--;
    
    for (int i = 0; i < n; i++) {
        bool chk = true;
        int schedule = schedules[i];
        const vector<int> &timelog = timelogs[i];
        
        int hour = schedule / 100;
        int minute = schedule % 100;
        minute += 10;
        if (minute >= 60) hour++, minute -= 60;
        
        for (int k = 0; k < 7; k++) {
            int day = (startday + k) % 7;
            if (day == 5 || day == 6) continue;

            int t = timelog[k];
            int logHour = t / 100;
            int logMinute = t % 100;

            if (logHour > hour) chk = false;
            else if (logHour == hour && logMinute > minute) chk = false;
        }
        
        if (chk) answer++;
    }
    
    return answer;
}