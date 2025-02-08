#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int N;
map<string,int> site;
vector<int> graph[MAX];
vector<int> inverse[MAX];
string target;

int t = 0;
int vis[MAX], fin[MAX];

vector<vector<int>> scc;
stack<int> st;

int g = 0;
int group[MAX];

long long D[MAX];

void input() {
    cin >> N;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        string name; cin >> name;
        if (!site.count(name)) site[name] = cnt++;

        int x; cin >> x;
        for (int j = 0; j < x; j++) {
            string other; cin >> other;
            if (!site.count(other)) site[other] = cnt++;

            graph[site[other]].push_back(site[name]);
            inverse[site[name]].push_back(site[other]);
        }
    }

    cin >> target;
    N = cnt;
}

int dfs(int cur) {
    vis[cur] = ++t;
    int low = vis[cur];
    st.push(cur);

    for (int nxt : graph[cur]) {
        if (!vis[nxt]) {
            low = min(low, dfs(nxt));
        }
        else if (!fin[nxt]) {
            low = min(low, vis[nxt]);
        }
    }

    if (low == vis[cur]) {
        vector<int> component;
        
        while (true) {
            int node = st.top();
            st.pop();
            
            component.push_back(node);
            fin[node] = low;
            group[node] = g;

            if (node == cur) break;
        }
        
        g++;
        scc.push_back(component);
    }

    return low;
}

void findscc() {
    for (int i = 0; i < N; i++) {
        if (!vis[i]) dfs(i);
    }
}

long long solve(int cur) {
    if (D[cur]) return D[cur];

    long long cnt = 0;
    for (int nxt : inverse[cur]) {
        if (group[cur] == group[nxt]) continue;
        cnt += solve(nxt);
    }
    
    return D[cur] = ++cnt;
}

int main() {
    FastIO
    input();
    findscc();

    long long ans = solve(site[target]);
    cout << ans << '\n';
    return 0;
}
