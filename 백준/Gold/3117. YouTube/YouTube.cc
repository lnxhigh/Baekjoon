#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100'001;

int n, k, m;
int arr[MAX];
int par[MAX][30];

int main() {
    FastIO

    cin >> n >> k >> m; m--;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= k; i++) {
        cin >> par[i][0];
    }

    for (int t = 0; t + 1 < 30; t++) {
        for (int i = 1; i <= k; i++) {
            par[i][t + 1] = par[par[i][t]][t];
        }
    }

    for (int i = 1; i <= n; i++) {
        int x = arr[i];
        for (int t = 0; t < 30; t++) {
            if (m >> t & 1) x = par[x][t];
        }
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
