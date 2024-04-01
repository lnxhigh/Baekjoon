#include <bits/stdc++.h>
using namespace std;

int N;
string str;

bool check(string str) {
    stack<char> st;
    for (char c : str) {
        if (c == '(' || c == '[') st.push(c);
        else if (c == ')' || c == ']') {
            if (st.empty()) return false;

            if (c == ')' && st.top() != '(') return false;
            else if (c == ']' && st.top() != '[') return false;
            else st.pop();
        }
    }
    if (st.empty()) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    while (true) {
        getline(cin, str);
        if (str == ".") break;
        string answer = check(str) ? "yes" : "no" ;
        cout << answer << '\n';
    }
    
    return 0;
}