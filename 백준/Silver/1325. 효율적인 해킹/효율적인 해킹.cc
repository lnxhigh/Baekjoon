#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

// TLE Test

int V, E;
const int MAX = 10000;
vector<int> graph[MAX];
int res[MAX];

int dfs(int cur, vector<int> &visited) {
    int res = 1;
    visited[cur] = true;

    for (int next : graph[cur]) {
        if (!visited[next]) res += dfs(next, visited);
    }
    return res;
}

int main() {
    FastIO
    
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        --A; --B;
        graph[B].push_back(A);
    }

    for (int i = 0; i < V; i++) {
        vector<int> visited(V);
        res[i] = dfs(i, visited);
    }

    int ans = *max_element(res, res + V);
    for (int i = 0; i < V; i++) {
        if (res[i] == ans) cout << i + 1 << ' ';
    }
    cout << '\n';
    
    return 0;
}
