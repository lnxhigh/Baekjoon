#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 10001;

int N, X;
int V[MAX];
bool G[MAX], C[MAX];
int D[MAX][2];

void input() {
    cin >> N >> X;
    assert(N % 2 == 1);

    memset(V, -1, sizeof(V));
    memset(G, false, sizeof(G));
    memset(C, false, sizeof(C));
    memset(D, -1, sizeof(D));

    int cnt = (N - 1) / 2;
    for (int i = 1; i <= cnt; i++) {
        cin >> G[i] >> C[i];
    }
    for (int i = cnt + 1; i <= N; i++) {
        cin >> V[i];
    }
}

bool isLeaf(int x) {
    return (x * 2) > N;
}

int dfs(int x) {
    if (V[x] != -1) return V[x];
    bool l = dfs(x * 2), r = dfs(x * 2 + 1);
    return V[x] = G[x] ? (l && r) : (l || r);
}

int dfs(int x, int target) {
    int &ret = D[x][target];
    if (ret != -1) return ret;
    else if (V[x] == target) return ret = 0;
    else if (isLeaf(x)) return ret = MAX;

    int l = x * 2, r = x * 2 + 1;

    if (target == 0) {
        int a = dfs(l, 0), b = dfs(r, 0);

        // AND GATE
        if (G[x]) {
            ret = min(a, b);
        }
        // OR GATE
        else {
            if (C[x]) ret = min(min(a, b) + 1, a + b);
            else ret = a + b;
        }
    }
    else {
        int a = dfs(l, 1), b = dfs(r, 1);

        // AND GATE
        if (G[x]) {
            if (C[x]) ret = min(min(a, b) + 1, a + b);
            else ret = a + b;
        }
        // OR GATE 
        else {
            ret = min(a, b); 
        }
    }
    
    return min(ret, MAX);
}

int main() {
    FastIO
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        input();
        dfs(1);
        int ans = dfs(1, X);
        string print = (ans < MAX) ? to_string(ans) : "IMPOSSIBLE";
        cout << "Case #" << t << ": " << print << '\n';
    }

    return 0;
}
