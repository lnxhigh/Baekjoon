#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 250'001;

long long ans = 0;
int h[MAX], l[MAX], r[MAX];
set<int> low, high;

int main() {
    FastIO

    int n; cin >> n;
    while (n--) {
        int x; cin >> x; x++;
        
        auto a = low.upper_bound(x);
        auto b = high.upper_bound(-x);

        int p = 0;
        if ((a != low.end()) && (l[*a] == 0)) p = *a;
        else if ((b != high.end() && (r[-(*b)] == 0))) p = -(*b);

        h[x] = h[p] + 1;
        ans += (long long) h[x];
        if (p) x < p ? l[p] = x : r[p] = x;

        low.insert(x);
        high.insert(-x);
    }

    cout << ans << '\n';

    return 0;
}
