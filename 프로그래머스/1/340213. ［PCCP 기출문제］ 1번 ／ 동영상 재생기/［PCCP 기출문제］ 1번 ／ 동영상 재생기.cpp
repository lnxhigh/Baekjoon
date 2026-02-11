#include <bits/stdc++.h>

using namespace std;

int f(string t) {
    // mm:ss
    int m = stoi(t.substr(0, 2));
    int s = stoi(t.substr(3, 2));
    return m * 60 + s;
}

string convert(int t) {
    int m = t / 60;
    int s = t % 60;
    
    string mm = (m < 10) ? "0" + to_string(m) : to_string(m);
    string ss = (s < 10) ? "0" + to_string(s) : to_string(s);
    
    return mm + ":" + ss;
}

string solution(string video_len_str, string pos_str, string op_start_str, string op_end_str, vector<string> commands) {
    
    int video_len = f(video_len_str);
    int pos = f(pos_str);
    int op_start = f(op_start_str);
    int op_end = f(op_end_str);
    
    // Init
    int ans = pos;
    if (ans >= op_start && ans <= op_end) {
        ans = op_end;
    }
    
    // Do
    for (string& command : commands) {
        if (command == "prev") {
            ans -= 10;
            ans = max(ans, 0);
        } else if (command == "next") {
            ans += 10;
            ans = min(ans, video_len);
        }
        
        if (ans >= op_start && ans <= op_end) {
            ans = op_end;
        } 
    }
    
    string answer = convert(ans);
    return answer;
}