#include <bits/stdc++.h>
#define V_MAX 20001
using namespace std;

int T;

bool BFS(int start, vector<int> graph[V_MAX], bool visited[V_MAX], bool color[V_MAX]) {
    queue<int> q;
    bool res = true;

    q.push(start);
    visited[start] = true;
    color[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : graph[cur]) {
            if (visited[next]) {
                if (color[next] == color[cur]) {
                    res = false;
                }
                continue;
            }
            visited[next] = true;
            color[next] = !color[cur];
            q.push(next);
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;
        vector<int> graph[V_MAX];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool visited[V_MAX] = { false, };
        bool color[V_MAX];

        bool res = true;
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                bool tmp = BFS(i, graph, visited, color);
                if (!tmp) {
                    res = false;
                    break;
                }
            }
        }
        
        string answer = res ? "YES" : "NO"; 
        cout << answer << '\n';
    }
    
    return 0;
}
