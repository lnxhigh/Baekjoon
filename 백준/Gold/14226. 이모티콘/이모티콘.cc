#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int S;
bool D[MAX][MAX];

int solve() {
    int ret = S;

    queue<tuple<int,int,int>> q;
    q.push({ 1, 0, 0 });
    D[1][0] = true;

    while (!q.empty()) {
        auto [x, k, t] = q.front();
        q.pop();
        
        if (x == S) {
            ret = min(ret, t);
            continue;
        }
        
        if (t >= ret) {
            continue;
        }

        // save
        if (!D[x][x]) {
            q.push({ x, x, t + 1 });
            D[x][x] = true;
        }

        // copy
        if (x + k <= S) {
            if (!D[x + k][k]) {
                q.push({ x + k, k, t + 1 });
                D[x + k][k] = true;
            }
        }
        else {
            ret = min(ret, (t + 1) + ((x + k) - S));
        }

        // erase
        if (x > 0) {
            if (!D[x - 1][k]) {
                q.push({ x - 1, k, t + 1 });
                D[x - 1][k] = true;
            }
        }
    }

    return ret;
}

int main() {
    FastIO
    cin >> S;

    int ans = solve();
    cout << ans << '\n';
    return 0;
}
