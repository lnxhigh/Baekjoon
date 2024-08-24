#include <bits/stdc++.h>
using namespace std;

int N;
string S;

int solve(const string &S) {
    int res = 0;
    stack<char> st;
    for (char c : S) {
        if (st.empty() || st.top() == c) st.push(c);
        else st.pop();
        res = max(res, (int) st.size());
    }

    if (!st.empty()) res = -1;
    return res;
}

int main() {
    cin >> N >> S;
    cout << solve(S) << '\n';
    return 0;
}
