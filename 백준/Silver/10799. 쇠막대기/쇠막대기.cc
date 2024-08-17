#include <bits/stdc++.h>
using namespace std;

string stick;
stack<int> st;
const int MAX = 1 << 17;
int res = 0;

int main() {
    cin >> stick;

    for (int i = 0; i < (int) stick.size(); i++) {
        char par = stick[i];
        if (par == '(') {
            st.push(par);
        }
        else if (par == ')') {
            st.pop();
            bool isLaser = (stick[i-1] == '(');
            res += isLaser ? (int) st.size() : 1;
        }
    }

    cout << res << '\n';
    return 0;
}
