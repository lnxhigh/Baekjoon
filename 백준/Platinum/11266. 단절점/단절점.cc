#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 10000;

vector<int> graph[MAX];
int visited[MAX];
int visitTime = 0;
bool art[MAX];

int dfs(int cur, bool root) {
    visited[cur] = ++visitTime;
    int res = visited[cur];

    // child 는 DFS 트리에서의 child 를 의미하는 것임 ...
    int child = 0;

    for (int next : graph[cur]) {
        if (!visited[next]) {
            child++;
            int t = dfs(next, false);
            if (t >= visited[cur]) art[cur] = true;
            res = min(res, t);
        }
        else {
            res = min(res, visited[next]);
        }
    }

    if (root) art[cur] = child > 1;

    return res;
}

int main() {
    FastIO

    int V, E; cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int A, B; cin >> A >> B;
        --A, --B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    // 연결 그래프가 아닐 수도 있음 ...
    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfs(i, true);
    }

    vector<int> P;
    for (int i = 0; i < V; i++) {
        if (art[i]) P.push_back(i + 1);
    }

    cout << P.size() << '\n';
    for (int i : P) cout << i << ' ';
    cout << '\n';
    return 0;
}
