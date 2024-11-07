#include <bits/stdc++.h>
using namespace std;
using vertex = string;

unordered_map<vertex, bool> visited;
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

vector<vertex> generate(const vertex &v) {
    vector<vertex> ret;
    
    int s = find(v.begin(), v.end(), '0') - v.begin();
    int x = s / 3, y = s % 3;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

        vertex u = v;
        int t = nx * 3 + ny;
        swap(u[s], u[t]);
        ret.push_back(u);
    }

    return ret;
}

int bfs(vertex src, vertex dst) {
    queue<pair<vertex, int>> q;
    q.push({ src, 0 });
    visited[src] = true;

    while (!q.empty()) {
        auto [cur, depth] = q.front();
        if (cur == dst) return depth;
        q.pop();

        for (const vertex &next : generate(cur)) {
            if (!visited[next]) {
                visited[next] = true;
                q.push({ next, depth + 1 });
            }
        }
    }

    return -1;
}

int main() {
    vertex src, dst, all;
    for (int i = 0; i < 9; i++) {
        char c; cin >> c;
        src.push_back(c);
        dst.push_back(('0' + (i + 1) % 9));
        all.push_back('0' + i);
    }

    int ans = bfs(src, dst);
    cout << ans << '\n';
    return 0;
}
