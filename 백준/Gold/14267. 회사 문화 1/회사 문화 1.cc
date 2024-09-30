#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 100000;

vector<int> tree[MAX];
int64 A[MAX], P[MAX];

void dfs(int parent) {
    P[parent] += A[parent];
    for (int child : tree[parent]) {
        P[child] += P[parent];
        dfs(child);
    }
}

int main() {
    int N, M; cin >> N >> M;

    int x; cin >> x;
    assert(x == -1);

    for (int i = 1; i < N; i++) {
        cin >> x;
        tree[--x].push_back(i);
    }

    for (int i = 0; i < M; i++) {
        cin >> x;
        int64 w; cin >> w;
        A[--x] += w;
    }

    dfs(0);

    for (int i = 0; i < N; i++) {
        cout << P[i] << ' ';
    }
    cout << '\n';
    return 0;
}
