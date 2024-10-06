#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

vector<vector<int>> graph;
vector<pair<int,int>> bridge;
vector<int> visited;
int T = 0;

int dfs(int cur, int prev) {
    visited[cur] = ++T;
    int res = visited[cur];

    for (int next : graph[cur]) {
        // prev 를 기록해서 parent 를 포함하지 않도록 한다
        if (next == prev) continue;

        if (!visited[next]) {
            int low = dfs(next, cur);

            // next 가 parent 가 되면 예외가 생기므로 사전에 차단한다
            // strictly greater 로 back edge 를 판단
            
            if (low > visited[cur]) { 
                int x = min(cur, next), y = max(cur, next);
                bridge.push_back({ x, y });
            }
            
            res = min(res, low);
        }
        else {
            res = min(res, visited[next]);
        }
    }

    return res;
}

int main() {
    FastIO

    int V, E; cin >> V >> E;
    graph.resize(V);
    visited.resize(V);

    for (int i = 0; i < E; i++) {
        int A, B; cin >> A >> B;
        --A, --B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    dfs(0, -1);

    sort(bridge.begin(), bridge.end());
    cout << bridge.size() << '\n';
    for (const auto& [A, B] : bridge) {
        cout << A + 1 << ' ' << B + 1 << '\n';
    }

    return 0;
}
