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
    if (tree[x].L != -1) { res++; dfs(tree[x].L); }
    if (tree[x].R != -1) { res++; dfs(tree[x].R); }
    if (x == last) finish = true;
    if (!finish) res++;
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
