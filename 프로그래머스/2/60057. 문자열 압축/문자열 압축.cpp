#include <bits/stdc++.h>

using namespace std;

int f(const string &str, int len) {
    int n = str.size();
    vector<string> words;
    
    for (int i = 0; i < n; i += len) {
        string word = str.substr(i, len);
        words.push_back(word);
    }
    
    int w = words.size();
    int cur = 0, nxt = 0, sum = 0;
    
    while (cur < w) {
        while (nxt < w and words[cur] == words[nxt]) nxt++;
        
        int cnt = nxt - cur;
        int size = words[cur].size();
        
        int add = 0;
        for (int x = cnt; x > 0; x /= 10) add++;
        if (cnt <= 1) add = 0;
        size += add;
        
        sum += size, cur = nxt;
    }

    return sum;
}

int solution(string str) {
    int ans = 1 << 20;
    int len = str.size();
    
    for (int i = 1; i <= len; i++) {
        int cnt = f(str, i);
        ans = min(ans, cnt);
    }
    
    return ans;
}
