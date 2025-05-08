#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 500'001;

int n, q;
int tree[MAX];

int sum(int i) {
    int x = 0;
    while (i) x += tree[i], i -= i & -i;
    return x;
}

void update(int i, int x) {
    while (i <= n) tree[i] += x, i += i & -i;
}

int query(int i) {
    int x = 0;
    int lo = 0, hi = n;
    
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (sum(mid) < i) x = mid, lo = mid + 1;
        else hi = mid - 1;
    }
    
    return ++x;
}

int main() {
    FastIO
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(i, x);
    }

    cin >> q;
    while (q--) {
        int p, i, a; cin >> p >> i;
        if (p == 1) cin >> a, update(i, a);
        else if (p == 2) cout << query(i) << '\n';
    }

    return 0;
}
