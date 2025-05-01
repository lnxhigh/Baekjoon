#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 3001;

int n, m;
int mx[MAX], mn[MAX];
bool chk[MAX];

int main() {
    FastIO
    cin >> n >> m;
    while (n--) {
        int x, y; cin >> x >> y;
        x += m, y += m;
        
        mx[x] = chk[x] ? max(mx[x], y) : y;
        mn[x] = chk[x] ? min(mn[x], y) : y;
        chk[x] |= true;
    }

    int ans = 0;

    for (int i = 0; i <= (m * 2); i++) {
        for (int j = i + 1; j <= (m * 2); j++) {
            if (!chk[i] || !chk[j]) continue;

            int dx = j - i;
            int dy[4] = { mx[j] - mx[i], mx[j] - mn[i], mn[j] - mx[i], mn[j] - mn[i] };

            for (int k = 0; k < 4; k++) {
                int r2 = dx * dx + dy[k] * dy[k];
                ans = max(ans, r2);
            }
        }
    }
    
    cout << ans << '\n';

    return 0;
}
