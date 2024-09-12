#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
#define L first
#define R second
using namespace std;

int N;
const int S = 1;
const int MAX = 100001;
pair<int,int> tree[MAX];

int last = S;
bool finish = false;
int res = 0;

void dfs(int x) {
    int l = tree[x].L, r = tree[x].R;
    if (l != -1) { res++; dfs(l); if (!finish) res++; }
    if (r != -1) { res++; dfs(r); if (!finish) res++; }
    if (x == last) finish = true;
}

int main() {
    FastIO
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, l, r; cin >> x >> l >> r;
        tree[x] = { l, r };
    }

    while (tree[last].R != -1) {
        last = tree[last].R;
    }

    dfs(S);

    cout << res << '\n';
    return 0;
}
