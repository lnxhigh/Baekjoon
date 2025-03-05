#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int A, B, X, Y;
map<pair<int,int>,bool> visited;

int main() {
    FastIO
    cin >> A >> B >> X >> Y;

    queue<tuple<int,int,int>> q;
    q.push({ 0, 0, 0 });
    visited[{0, 0}] = true;

    int ans = -1;

    while (!q.empty()) {
        auto [x, y, cnt] = q.front();
        q.pop();
        
        if (x == X && y == Y) { ans = cnt; break; }

        vector<pair<int,int>> nxt = {
            { A, y }, { x, B }, { 0, y }, { x, 0 },
            { min(x + y, A), max(x + y - A, 0) }, 
            { max(x + y - B, 0), min(x + y, B) }
        };

        for (auto &p : nxt) {
            if (!visited[p]) {
                q.push({ p.first, p.second, cnt + 1 });
                visited[p] = true;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
