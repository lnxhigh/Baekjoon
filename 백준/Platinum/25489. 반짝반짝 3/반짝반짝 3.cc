#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 500000;

int N, Q;
vector<int> tree[MAX];
double prob[MAX], sum[MAX];
int parent[MAX];
const int R = 0;
double value = 0;

void dfs(int cur) {
    for (int next : tree[cur]) {
        if (next != parent[cur]) {
            parent[next] = cur;
            sum[cur] += prob[next];
            dfs(next);
        }
    }
}

void update(int u, double p) {
    int T = (int) tree[u].size();
    if (u != R) T--;

    double x = prob[u];
    prob[u] = p;

    value -= x + T * x + sum[u] * (1.0 - 2.0 * x);
    value += p + T * p + sum[u] * (1.0 - 2.0 * p);
    if (u == R) return;

    int v = parent[u];
    double y = prob[v];
    value -= x * (1.0 - y) + (1.0 - x) * y;
    value += p * (1.0 - y) + (1.0 - p) * y;
    sum[v] -= x; 
    sum[v] += p;
}

int main() {
    FastIO
    cout << setprecision(16);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> prob[i];
    }

    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v; --u, --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(parent, -1, sizeof(parent));
    dfs(R);

    for (int i = 0; i < N; i++) {
        value += prob[i];
        for (int k : tree[i]) {
            if (i < k) {
                value += prob[i] * (1.0 - prob[k]);
                value += prob[k] * (1.0 - prob[i]);
            }
        }
    }

    cout << value << '\n';

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u; cin >> u; --u;
        double p; cin >> p;
        update(u, p);
        cout << value << '\n';
    }

    return 0;
}
