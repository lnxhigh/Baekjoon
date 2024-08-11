#include <bits/stdc++.h>
using namespace std;

int K, X;
stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> K;
    while (K--) {
        cin >> X;
        if (X == 0) st.pop();
        else st.push(X);
    }

    int res = 0;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    cout << res << '\n';
    return 0;
}
