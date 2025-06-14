#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 8;

int n, b, k;
int arr[MAX][MAX];
int mn[MAX][MAX], mx[MAX][MAX];

int main() {
    FastIO

    cin >> n >> b >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            mn[i][j] = mx[i][j] = arr[i][j];
        }
    }
    
    for (int i = 0; i <= n - b; i++) {
        for (int j = 0; j <= n - b; j++) {
            for (int x = 0; x < b; x++) {
                for (int y = 0; y < b; y++) {
                    mn[i][j] = min(mn[i][j], arr[i + x][j + y]);
                    mx[i][j] = max(mx[i][j], arr[i + x][j + y]);
                }
            }
        }
    }

    while (k--) {
        int i, j; cin >> i >> j; --i, --j;
        cout << mx[i][j] - mn[i][j] << '\n';
    }

    return 0;
}
