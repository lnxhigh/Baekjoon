#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

set<int> graph[10];
int jumps[10][10];

int path[10];
bool vis[10];
bool edge[10][10];

bool check() {
    for (int x = 1; x <= 9; x++) {
        for (int nxt : graph[x]) {
            if (!edge[x][nxt]) {
                return false;
            }
        }
    }

    return true;
}

void dfs(int x, int depth, int cnt, bool &finish) {
    if (finish) return;

    path[depth] = x;
    vis[x] = true;

    if (depth >= cnt) {
        finish |= check();
        if (!finish) path[depth] = 0, vis[x] = false;
        return;
    }
    
    for (int nxt : graph[x]) {
        if (vis[nxt]) {
            int jump = jumps[x][nxt];
            if (jump == 0) continue;
            else if (!graph[nxt].count(jump) || vis[jump]) continue;

            bool flag = edge[x][nxt];

            edge[x][nxt] = edge[nxt][x] = true;
            edge[nxt][jump] = edge[jump][nxt] = true;
            dfs(jump, depth + 1, cnt, finish);
            edge[x][nxt] = edge[nxt][x] = flag;
            edge[nxt][jump] = edge[jump][nxt] = false;
        }
        else {
            edge[x][nxt] = edge[nxt][x] = true;
            dfs(nxt, depth + 1, cnt, finish);
            edge[x][nxt] = edge[nxt][x] = false;
        }

        if (finish) return;
    }

    path[depth] = 0;
    vis[x] = false;
}

int main() {
    FastIO
    int tc; cin >> tc;

    jumps[1][2] = 3, jumps[1][4] = 7, jumps[1][5] = 9;
    jumps[3][2] = 1, jumps[3][6] = 9, jumps[3][5] = 7;
    jumps[7][4] = 1, jumps[7][8] = 9, jumps[7][5] = 3;
    jumps[9][8] = 7, jumps[9][6] = 3, jumps[9][5] = 1;
    
    jumps[2][5] = 8, jumps[4][5] = 6, jumps[6][5] = 4, jumps[8][5] = 2;

    while (tc--) {
        for (int i = 0; i < 10; i++) graph[i].clear();
        memset(path, 0, sizeof(path));

        int e; cin >> e;
        bool nodes[10] = {false};

        while (e--) {
            int x, y; cin >> x >> y;

            int idx = -1;
            for (int i = 1; i <= 9; i++) {
                if (jumps[x][i] == y || jumps[y][i] == x) {
                    idx = i;
                    break;
                }
            }

            if (idx == -1) {
                graph[x].insert(y);
                graph[y].insert(x);
                nodes[x] = nodes[y] = true;
            }
            else {
                graph[x].insert(idx);
                graph[idx].insert(x);
                graph[y].insert(idx);
                graph[idx].insert(y);

                nodes[x] = nodes[y] = nodes[idx] = true;
            }
        }

        int cnt = 0;
        bool finish = false;

        for (int i = 1; i <= 9; i++) {
            if (nodes[i]) cnt++;
        }

        for (int i = 1; i <= 9; i++) {
            memset(vis, false, sizeof(vis));
            memset(edge, false, sizeof(edge));
            dfs(i, 1, cnt, finish);
        }
        
        if (finish) {
            for (int i = 1; i <= cnt; i++) {
                cout << path[i] << ' ';
            }
            cout << '\n';
        }
        else {
            cout << "IMPOSSIBLE" << '\n';
        }
    }

    return 0;
}
