#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100000;

int E[MAX];
vector<pair<int,int>> graph[MAX];

// dfs
pair<int,int> P[MAX];
bool visited[MAX];

// sparse matrix
const int K = 17;
pair<int,int> D[MAX][K];

// Track Parent
void dfs(int cur) {
    visited[cur] = true;
    for (const auto& [next, len] : graph[cur]) {
        if (visited[next]) continue;
        P[next] = { cur, len };
        dfs(next);
    }
}

// Build Sparse Matrix
int move(int i) {
    int x = i;
    int energy = E[i];

    for (int k = K-1; k >= 0; k--) {
        if (x == 0 || energy == 0) break;

        const auto& [next, len] = D[x][k];
        if (len > energy) continue;

        // move
        x = next;
        energy -= len;
    }

    return x;
}

int main() {
    FastIO

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> E[i];

    for (int i = 0; i < N - 1; i++) {
        int a, b, len; cin >> a >> b >> len;
        --a, --b;
        graph[a].push_back({ b, len });
        graph[b].push_back({ a, len });
    }

    dfs(0);

    for (int i = 0; i < N; i++) D[i][0] = P[i];
    for (int k = 0; k < K-1; k++) {
        for (int i = 0; i < N; i++) {
            auto& [next, len] = D[i][k+1];
            int m = D[i][k].first;
            next = D[m][k].first;
            len  = D[i][k].second + D[m][k].second;
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << move(i) + 1 << '\n';
    }

    return 0;
}
