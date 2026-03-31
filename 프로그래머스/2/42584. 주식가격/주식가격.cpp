#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    stack<int> st;
    vector<int> ans(n);
    
    for (int t = 0; t < n; t++) {
        while (!st.empty() and prices[st.top()] > prices[t]) {
            int x = st.top();
            st.pop();
            ans[x] = t - x;
        }
        st.push(t);
    }
    
    while (!st.empty()) {
        int x = st.top();
        st.pop();
        ans[x] = n - x - 1;
    }
    
    return ans;
}
