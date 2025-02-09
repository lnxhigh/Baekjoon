#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int N, M;
vector<int> graph[MAX];
int X, Y;

int K;
set<int> C;

int D[MAX][MAX];
int inDegree[MAX];

void input() {
    cin >> N >> M;
    while (M--) {
        int A, B; cin >> A >> B;
        graph[A].push_back(B);
        inDegree[B]++;
    }
    cin >> X >> Y;

    cin >> K;
    for (int i = 0; i < K; i++) {
        int V; cin >> V;
        C.insert(V);
    }
}

vector<int> toposort() {
    // Topological Sort
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        int cur = q.front();
        q.pop();
        
        vec[i] = cur;
        for (int nxt : graph[cur]) {
            if (--inDegree[nxt] == 0) q.push(nxt);
        }
    }

    return vec;
}

int dfs(int i, int j) {
    if (D[i][j] != -1) return D[i][j];
    else if (i == j) return D[i][j] = 1;
    
    int cnt = 0;
    for (int k : graph[i]) {
        cnt += dfs(k, j);
    }
    return D[i][j] = cnt;
}

int main() {
    FastIO
    input();

    int ans = 1, cur = X;
    auto topo = toposort();
    memset(D, -1, sizeof(D));
    
    for (int i : topo) {
        if (ans == 0) break;
        else if (!C.count(i)) continue;
        ans *= dfs(cur, i);
        cur = i;
    }

    ans *= dfs(cur, Y);
    cout << ans << '\n';
    return 0;
}
