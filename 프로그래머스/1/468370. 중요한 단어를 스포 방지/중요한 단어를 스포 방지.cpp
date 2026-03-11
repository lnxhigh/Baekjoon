#include <bits/stdc++.h>

using namespace std;

int solution(string msg, vector<vector<int>> ranges) {
    int len = msg.size();
    vector<bool> chk(len);
    unordered_set<string> res;
    
    // Init
    
    for (auto range : ranges) {
        int x = range[0], y = range[1];
        for (int i = x; i <= y; i++) chk[i] = true;
    }
    
    // Search
    
    for (auto range : ranges) {
        int idx = 0;
        int x = range[0], y = range[1];
        unordered_set<string> opened;
        vector<string> revealed;
        
        while (idx < len) {
            string word = "";
            bool open = true;
            bool reveal = false;
            
            while (idx < len && msg[idx] == ' ') {
                idx++;
            }
            while (idx < len && msg[idx] != ' ') {
                word.push_back(msg[idx]);
                if (chk[idx]) open = false;
                if (idx >= x && idx <= y) reveal = true;
                
                idx++;
            }
            
            if (open) opened.insert(word);
            if (reveal) revealed.push_back(word);
        }
        
        for (int i = x; i <= y; i++) {
            chk[i] = false;
        }
        
        for (const string &word : revealed) {
            if (opened.find(word) == opened.end()) {
               res.insert(word);
            }

        }
    }
    
    int cnt = res.size();
    return cnt;
}
