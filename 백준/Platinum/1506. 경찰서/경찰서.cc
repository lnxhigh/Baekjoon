#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100;

int n;
int arr[MAX];
bool adj[MAX][MAX];

int par[MAX];
vector<int> res[MAX];

int find(int x) {
    if (x == par[x]) return x;
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

    // Input

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char x; cin >> x;
            adj[i][j] = (bool) (x - '0');
        }
    }

    // Floyd

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] |= (adj[i][k] && adj[k][j]);
            }
        }
    }

    // DSU

    iota(par, par + n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] && adj[j][i]) {
                merge(i, j);
            }
        }
    }

    // Answer

    int ans = 0;

    for (int i = 0; i < n; i++) {
        res[find(i)].emplace_back(arr[i]);
    }
    
    for (int i = 0; i < n; i++) {
        if (res[i].empty()) continue;
        sort(res[i].begin(), res[i].end());
        ans += *res[i].begin();
    }
    
    cout << ans << '\n';
    
    return 0;
}
