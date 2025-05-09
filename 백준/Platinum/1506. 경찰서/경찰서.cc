#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100;

int n;
vector<int> arr;
vector<string> adj;

int t = 1;
stack<int> st;
int vis[MAX], fin[MAX];

int ans = 0;

int dfs(int x) {
    vis[x] = t++;
    st.push(x);
    int low = vis[x];

    for (int nxt = 0; nxt < n; nxt++) {
        if (adj[x][nxt] != '1') continue;
        
        if (!vis[nxt]) low = min(low, dfs(nxt));
        else if (!fin[nxt]) low = min(low, vis[nxt]);
    }

    if (low == vis[x]) {
        int add = 0;

        while (!st.empty()) {
            int top = st.top();
            st.pop();

            fin[top] = low;
            add = add ? min(add, arr[top]) : arr[top];
            
            if (top == x) break;
        }

        ans += add;
    }
    
    return low;
}

int main() {
    FastIO

    cin >> n;
    arr.resize(n), adj.resize(n);
    for (int& x : arr) cin >> x;
    for (string& line : adj) cin >> line;

    for (int i = 0; i < n; i++) {
        if (!fin[i]) dfs(i);
    }
    
    cout << ans << '\n';
    return 0;
}
