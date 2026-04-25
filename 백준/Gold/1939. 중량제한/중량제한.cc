#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 10001;

int n, m;
vector<tuple<int,int,int>> arr;

int from, to;
int par[MAX];

int find(int x) {
    if (!par[x]) return x;
    return par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    else if (x < y) swap(x, y);
    
    par[x] = y;
    return true;
}

int main() {
    FastIO

    cin >> n >> m;
    arr.resize(m);
    for (auto& [w, a, b] : arr) cin >> a >> b >> w;
    sort(arr.rbegin(), arr.rend());
    cin >> from >> to;

    int ans = 0;
    for (const auto& [w, a, b] : arr) {
        ans = w;
        merge(a, b);
        if (find(from) == find(to)) break;
    }

    cout << ans << '\n';
    return 0;
}
