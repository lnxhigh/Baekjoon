#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100'005;

int n;
int arr[MAX];
pair<int,int> sorted[MAX];
int par[MAX], sz[MAX];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    else if (x < y) swap(x, y);
    par[x] = y, sz[y] += sz[x];
}

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        auto& [t, idx] = sorted[i];
        t = arr[i], idx = i;
    }

    sort(sorted, sorted + n);
    iota(par, par + n, 0);
    fill(sz, sz + n, 1);

    long long ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        auto [t, idx] = sorted[i];

        if (idx > 0 && arr[idx - 1] >= arr[idx]) merge(idx - 1, idx);
        if (idx < n - 1 && arr[idx + 1] >= arr[idx]) merge(idx, idx + 1);

        long long len = sz[find(idx)];
        ans = max(ans, len * t);
    }
    
    cout << ans << '\n';
    return 0;
}
