#include <bits/stdc++.h>
using namespace std;

int main() {
    string str; cin >> str;
    stack<int> st;

    int len = str.size();
    for (int i = 0; i < len; i++) {
        char x = str[i];
        if (x == '(') {
            st.pop();
            st.push(str[i - 1] - '0');
            st.push(-1);
        }
        else if (x == ')') {
            int sum = 0;
            while (st.top() != -1) sum += st.top(), st.pop();
            st.pop();
            sum *= st.top();
            
            st.pop();
            st.push(sum);
        }
        else {
            st.push(1);
        }
    }

    int ans = 0;
    while (!st.empty()) ans += st.top(), st.pop();
    cout << ans << '\n';

    return 0;    
}
