#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

string solve(const string &S) {
    string ret;
    stack<char> l, r;
    
    for (char c : S) {
        if (c == '-') {
            if (!l.empty()) {
                l.pop();
            }
        }
        else if (c == '<') {
            if (!l.empty()) {
                r.push(l.top());
                l.pop();
            }
        }
        else if (c == '>') {
            if (!r.empty()) {
                l.push(r.top());
                r.pop();
            }
        }
        else {
            l.push(c);
        }
    }
    
    while (!l.empty()) {
        r.push(l.top());
        l.pop();
    }
    while (!r.empty()) {
        ret.push_back(r.top());
        r.pop();
    }
    
    return ret;
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        string S; cin >> S;
        cout << solve(S) << '\n';
    }
    return 0;
}
