#include <bits/stdc++.h>

using namespace std;
const int MAX = 1 << 20;

int prv[MAX];
int nxt[MAX];

string solution(int n, int k, vector<string> commands) {
    string ans = string(n, 'O');
    int cur = k;
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        nxt[i] = i + 1;
        prv[i] = i - 1;
    }
    prv[0] = nxt[n - 1] = -1;
    
    for (const string &cmd : commands) {
        char op = cmd[0];
        
        if (op == 'U') {
            int cnt = stoi(cmd.substr(2));
            while (cnt > 0 and prv[cur] != -1) cnt--, cur = prv[cur];
        }
        else if (op == 'D') {
            int cnt = stoi(cmd.substr(2));
            while (cnt > 0 and nxt[cur] != -1) cnt--, cur = nxt[cur];
        }
        else if (op == 'C') {
            ans[cur] = 'X';
            st.push(cur);
            
            if (prv[cur] != -1) nxt[prv[cur]] = nxt[cur];
            if (nxt[cur] != -1) prv[nxt[cur]] = prv[cur];
            
            if (nxt[cur] != -1) cur = nxt[cur];
            else if (prv[cur] != -1) cur = prv[cur];
        }
        else if (op == 'Z') {
            if (st.empty()) continue;
            int top = st.top();
            ans[top] = 'O';
            st.pop();
            
            if (prv[top] != -1) nxt[prv[top]] = top;
            if (nxt[top] != -1) prv[nxt[top]] = top;
        }
    }
    
    return ans;
}
