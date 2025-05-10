#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 100'001;

ll n, m;
ll par[MAX], diff[MAX];

ll find(ll x) {
    if (!par[x]) return x;
    ll p = find(par[x]);
    diff[x] += diff[par[x]];
    return par[x] = p;
}

bool merge(ll x, ll y, ll w) {
    // update diff first
    ll px = find(x), py = find(y);
    if (px == py) return false;

    // now merge
    par[px] = py, diff[px] = diff[y] - diff[x] - w;
    return true;
}

int main() {
    FastIO
    while (cin >> n >> m, n && m) {
        char c;
        ll a, b, w;

        for (int i = 0; i <= n; i++) {
            par[i] = diff[i] = 0;
        }
        
        while (m--) {
            cin >> c;

            if (c == '!') {
                cin >> a >> b >> w;
                merge(a, b, w);
            }
            else if (c == '?') {
                cin >> a >> b;
                bool chk = (find(a) == find(b));
                if (chk) cout << diff[b] - diff[a] << '\n';
                else cout << "UNKNOWN" << '\n';
            }
        }
    }
    
    return 0;
}
