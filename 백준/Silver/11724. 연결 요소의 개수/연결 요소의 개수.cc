#include <iostream>
#include <vector>
using namespace std;

int N, E;
int u, v;
vector<int> graph[1001];
bool visited[1001] = {false,};

void dfs(int i) {
    for (int x : graph[i]) {
        if (visited[x]) continue;
        visited[x] = true;
        dfs(x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int component = 0;
    for (int i = 1; i <= N; i++) {
        if (not visited[i]) {
            component++;
            visited[i] = true;
            dfs(i);
        }
    }
    
    cout << component;
}