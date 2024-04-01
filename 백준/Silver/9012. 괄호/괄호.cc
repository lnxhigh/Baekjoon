#include <bits/stdc++.h>
using namespace std;

bool checkVPS(string str) {
    stack<char> st;
    for (char c : str) {
        if (c == '(') st.push(c);
        else if (c == ')') {
            if (st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string str;
        cin >> str;
        string answer = checkVPS(str) ? "YES" : "NO" ;
        cout << answer << '\n';
    }
    
    return 0;
}