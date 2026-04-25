#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N;
int parent, child, weight;

vector<vector<pair<int, int>>> tree(10001);
vector<int> parents(10001);
vector<int> value(10001);
vector<int> leaf;
vector<int> depth;
int answer = 0;
int Max (int x, int y) { return x > y ? x : y ; }

void dfs(int parent, int k, int height) {
    for (auto x : tree[parent]) {
        dfs(x.first, k+x.second, height+1);
    }

    if (tree[parent].empty()) {
        leaf.push_back(parent);
        depth.push_back(height);
    }

    value[parent] = k;
}

int findAncestor(int x, int y, int hx, int hy) {
    if (hx > hy) { for (int i = 0; i < hx-hy; i++) x = parents[x]; }
    else if (hx < hy) { for (int i = 0; i < hy-hx; i++) y = parents[y]; }
    while (x != y) {
        x = parents[x];
        y = parents[y];
    }
    
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;

    if (N == 1) {
        cout << 0;
        return 0;
    }

    parents[1] = 1;
    for (int i = 0; i < N-1; i++) {
        cin >> parent >> child >> weight;
        tree[parent].push_back({child, weight});
        parents[child] = parent;
    }
    
    leaf.push_back(1);
    depth.push_back(0);
    dfs(1, 0, 0);

    int l = leaf.size();

    for (int i = 0; i < l; i++) {
        for (int j = i+1; j < l; j++) {
            int p = findAncestor(leaf[i], leaf[j], depth[i], depth[j]);
            answer = Max(answer, value[leaf[i]] + value[leaf[j]] - 2*value[p]);
        }
    }

    cout << answer;

    return 0;
}