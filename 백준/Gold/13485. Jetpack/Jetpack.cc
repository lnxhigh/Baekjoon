#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100'001;

int r = 10, n = 0;
vector<string> arr;

int pre[10][MAX];
bool vis[10][MAX];
bool chk[MAX];

int main() {
    FastIO

    cin >> n;
    arr.resize(r);
    for (string& str : arr) cin >> str;

    queue<int> q;
    q.push((r - 1) * n);
    vis[r - 1][0] = true;

    bool gameover = false;
    int last = 0;

    while (!q.empty() && !gameover) {
        int t = q.front();
        q.pop();
        int x = t / n, y = t % n;
        
        if (y == n - 1) gameover = true, last = x;
        if (gameover) break;

        for (int nxt : { x - 1, x + 1 }) {
            nxt = max(nxt, 0);
            nxt = min(nxt, r - 1);

            if (arr[nxt][y + 1] != 'X' && !vis[nxt][y + 1]) {
                q.push(nxt * n + (y + 1));
                vis[nxt][y + 1] = true;
                pre[nxt][y + 1] = t;
            }
        }
    }

    int x = last, y = n - 1;

    while (y) {
        int t = pre[x][y];
        int px = t / n, py = t % n;
        chk[py] |= (x < px) || (x == px && x == 0);
        x = px, y = py;
    }

    int t = 0, hold = 0;
    vector<pair<int,int>> res;

    for (int i = 0; i < n; i++) {
        if (chk[i]) {
            if (!hold) t = i;
            hold++;
        }
        else {
            if (hold) res.emplace_back(t, hold);
            t = hold = 0;
        } 
    }

    cout << res.size() << '\n';
    for (auto [t, x] : res) cout << t << ' ' << x << '\n';

    return 0;
}
