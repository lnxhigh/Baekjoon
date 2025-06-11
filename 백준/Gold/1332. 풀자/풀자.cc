#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int n, v;
vector<int> arr;

int bfs(int from, int to, int x, int y) {
    queue<pair<int,int>> q;
    vector<bool> vis(n);

    q.push({ from, 0 });
    vis[from] = true;

    while (!q.empty()) {
        auto [cur, cnt] = q.front();
        q.pop();
        
        if (cur == to) return cnt;
        for (int nxt : { cur + 1, cur + 2 }) {
            if (nxt < n && arr[nxt] >= x && arr[nxt] <= y && !vis[nxt]) {
                q.push({ nxt, cnt + 1 });
                vis[nxt] = true;
            }
        }
    }

    return -1;
}

int main() {
    FastIO
    
    cin >> n >> v;
    arr.resize(n);
    for (int& x : arr) cin >> x;

    int ans = n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = min(arr[i], arr[j]), y = max(arr[i], arr[j]);
            if (arr[0] < x || arr[0] > y || (y - x) < v) continue;

            int fir = bfs(0, min(i, j), x, y);
            int sec = bfs(min(i, j), max(i, j), x, y);

            if (fir == -1 || sec == -1) continue;
            
            int add = fir + sec + 1;
            ans = min(ans, add);
        }
    }

    cout << ans << '\n';
    return 0;
}
