#include <bits/stdc++.h>
#define V_MAX 1001
using namespace std;

int V, E, S;
vector<int> graph[V_MAX];
bool visited[V_MAX];

void DFS(int start) {
    cout << start << ' ';
    visited[start] = true;

    for (int next : graph[start]) {
        if (!visited[next]) DFS(next);
    }
}

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for (int next : graph[cur]) {
            if (visited[next]) continue;
            q.push(next);
            visited[next] = true;
        }
    }
}

int main() {
    cin >> V >> E >> S;
    for (int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= V; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(S);
    cout << '\n';
    fill(visited, visited + V_MAX, false);
    
    BFS(S);
    cout << '\n';

    return 0;
}
