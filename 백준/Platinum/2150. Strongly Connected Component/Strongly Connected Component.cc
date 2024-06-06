#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define V_MAX 10001
using namespace std;

int V, E;
vector<int> graph[V_MAX];

stack<int> st;
int visitTime = 0;
int visited[V_MAX];
bool finished[V_MAX];

vector<vector<int>> SCC;

int DFS(int start) {
    visited[start] = ++visitTime;
    st.push(start);

    int res = visited[start];
    for (int next : graph[start]) {
        if (!visited[next]) res = min(res, DFS(next));
        else if (!finished[next]) res = min(res, visited[next]);
    }
    
    if (res == visited[start]) {
        vector<int> scc;
        while (true) {
            int top = st.top();
            finished[top] = true;
            scc.push_back(top); 
            st.pop();
            
            if (top == start) break;
        }

        SCC.push_back(scc);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }

    for (int i = 1; i <= V; i++) {
        if (visited[i]) continue;
        DFS(i);
    }

    for (vector<int> &scc : SCC) sort(all(scc));
    sort(all(SCC), [] (vector<int> &left, vector<int> &right) {
        return left[0] < right[0];
    });

    cout << SCC.size() << '\n';
    for (vector<int> &scc : SCC) {
        for (int i : scc) cout << i << ' ';
        cout << -1 << '\n';
    }

    return 0;
}
