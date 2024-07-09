#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 51;
vector<int> tree[N_MAX];
int D[N_MAX];

int f(int root) {
    if (D[root] != -1) return D[root];
    if (tree[root].empty()) return D[root] = 0; 

    vector<int> v;
    for (int child : tree[root]) {
        v.push_back(f(child));
    }
    sort(v.begin(), v.end());

    int res = -1;
    int s = tree[root].size();
    for (int i = 0; i < s; i++) {
        res = max(res, v[i] + s - i);
    }

    return D[root] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    int parent;
    cin >> parent;
    for (int child = 1; child < N; child++) {
        cin >> parent;
        tree[parent].push_back(child);
    }

    memset(D, -1, sizeof(D));
    int res = f(0);
    cout << res << '\n';

    return 0;
}
