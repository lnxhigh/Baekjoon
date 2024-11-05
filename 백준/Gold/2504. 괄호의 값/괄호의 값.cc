#include <bits/stdc++.h>
using namespace std;
const string open  = "([";
const string close = ")]";

bool VPS(string s) {
    stack<char> st;
    for (char c : s) {
        if (open.find(c) != -1) {
            st.push(c);
        }
        else if (close.find(c) != -1) {
            if (st.empty() || st.top() != open[close.find(c)]) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

int solve(string s) {
    if (s.empty()) {
        return 1;
    }
    
    int len = (int) s.size();

    string inner = s.substr(1, len - 2);
    if (VPS(inner)) {
        int mul = open.find(s.front()) + 2;
        return mul * solve(inner);
    }
    
    for (int i = 2; i < len; i += 2) {
        string l = s.substr(0, i);
        string r = s.substr(i, len - i);
        if (VPS(l) && VPS(r)) return solve(l) + solve(r);
    }

    return 0;
}

int main() {
    string s; cin >> s;
    int ans = VPS(s) ? solve(s) : 0;
    cout << ans << '\n';
    return 0;
}
