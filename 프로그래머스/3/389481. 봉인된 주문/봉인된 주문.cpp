#include <bits/stdc++.h>
using namespace std;

string f(long long n) {
    if (n == 0) return "";
    
    int r = n % 26;
    if (r == 0) return f(n / 26 - 1) + "z";
    return f(n / 26) + string(1, 'a' + r - 1);
}

string next(string x) {
    int L = x.size();
    bool fin = false;
    
    for (int i = L - 1; i >= 0 && !fin; i--) {
        if (x[i] == 'z') x[i] = 'a';
        else x[i]++, fin = true;
    }
    
    if (!fin) x = "a" + x;
    return x;
}

string solution(long long n, vector<string> bans) {
    string answer = f(n);
    
    int cnt = 0;
    set<string> bs(bans.begin(), bans.end());
    
    for (const string &str : bs) {
        if (str.size() < answer.size()) cnt++;
        else if (str.size() == answer.size() && str <= answer) cnt++;
    }
    
    while (cnt) {
        cnt--;
        answer = next(answer);
        if (bs.find(answer) != bs.end()) cnt++;
    }
    
    return answer;
}