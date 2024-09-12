#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
const int MAX = 1 << 19;
vector<int> tree[MAX];
bool visited[MAX];
int depth[MAX];

void dfs(int parent, int k) {
    visited[parent] = true;
    depth[parent] = k;

    for (int child : tree[parent]) {
        if (!visited[child]) dfs(child, k+1);
    }
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    const int R = 1;
    dfs(R, 0);

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        bool isLeaf = ((int) tree[i].size() == 1);
        if (isLeaf) cnt += depth[i];
    }

    string ans = (cnt & 1) ? "Yes" : "No";
    cout << ans << '\n';
    return 0;
}
