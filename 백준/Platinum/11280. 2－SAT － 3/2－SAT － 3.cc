#include <bits/stdc++.h>
using namespace std;

int N, M;
const int N_MAX = 20001;
vector<int> graph[N_MAX];

stack<int> st;
int visitTime = 0;
int visited[N_MAX];
int finished[N_MAX];

vector<vector<int>> SCC;
int group[N_MAX];

int dfs(int cur) {
    visited[cur] = ++visitTime;
    st.push(cur);
    int res = visited[cur];

    for (int next : graph[cur]) {
        if (!visited[next]) res = min(res, dfs(next));
        else if (!finished[next]) res = min(res, visited[next]);
    }

    if (res == visited[cur]) {
        vector<int> scc;
        while (true) {
            int top = st.top();
            st.pop();
            scc.push_back(top);
            finished[top] = true;
            
            if (top == cur) break;
        }
        SCC.push_back(scc);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        // 참이면 홀수 거짓이면 짝수로 구현하면 코드가 간결해짐
        x = (x>0) ? 2*x-1 : -2*x;
        y = (y>0) ? 2*y-1 : -2*y;
        graph[x&1 ? x+1 : x-1].push_back(y);
        graph[y&1 ? y+1 : y-1].push_back(x);
    }

    for (int i = 1; i <= 2*N; i++) {
        if (!visited[i]) dfs(i);
    }

    int s = SCC.size();
    for (int i = 0; i < s; i++) {
        for (int k : SCC[i]) {
            group[k] = i;
        }
    }

    bool ans = true;
    for (int i = 1; i <= N; i++) {
        if (group[i*2] == group[i*2-1]) {
            ans = false;
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}
