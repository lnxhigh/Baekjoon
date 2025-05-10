#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 20'001;

int par[MAX];
int dist[MAX];

int find(int x) {
    int& p = par[x];
    if (p == 0) return x;

    int r = find(p);
    dist[x] += dist[p];
    return p = r;
}

int main() {
    FastIO

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        for (int i = 0; i <= n; i++) {
            par[i] = dist[i] = 0;
        }

        while (true) {
            char p; cin >> p;
            int i = 0, j = 0;

            if (p == 'O') {
                break;
            }
            else if (p == 'E') {
                cin >> i;
                find(i);
                cout << dist[i] << '\n';
            }
            else if (p == 'I') {
                cin >> i >> j;
                par[i] = j;
                dist[i] = abs(i - j) % 1000;
            }
        }
    }

    return 0;
}
