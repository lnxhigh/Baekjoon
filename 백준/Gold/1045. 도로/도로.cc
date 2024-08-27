#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define For(i, n) for (int i = 0; i < n; i++)
#define X first
#define Y second
using namespace std;

int N, M;
const int MAX = 1 << 6;
bool adj[MAX][MAX];
vector<pair<int,int>> edges;

int parent[MAX];
bool connected[MAX][MAX];
vector<int> res[MAX];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;

    if (a > b) { parent[a] = b; }
    else { parent[b] = a; }
    return true;
}

void solve() {
    int cnt = 0;
    for (auto p : edges) {
        int x = p.X, y = p.Y;
        bool isMerged = merge(x, y);
        if (isMerged) {
            cnt++;
            connected[x][y] = connected[y][x] = true;
            res[x].push_back(y);
            res[y].push_back(x);
        }
    }

    if (cnt < N-1) {
        cout << -1 << '\n';
        return;
    }

    For (i, N) {
        if (cnt == M) break;
        
        For (j, N) {
            if (cnt == M) break;

            if (!adj[i][j]) continue;
            if (connected[i][j]) continue;

            connected[i][j] = connected[j][i] = true;
            res[i].push_back(j);
            res[j].push_back(i);
            cnt++;
        }
    }

    if (cnt < M) {
        cout << -1 << '\n';
        return;
    }

    For (i, N) {
        cout << res[i].size() << ' ';
    }
    cout << '\n';
    
    return;
}

int main() {
    FastIO;
    
    cin >> N >> M;
    For (i, N) {
        For (j, N) {
            char c; cin >> c;
            adj[i][j] = (c == 'Y');

            if (i < j && adj[i][j]) {
                edges.push_back({ i, j });
            }
        }
    }

    iota(parent, parent + N, 0);
    sort(edges.begin(), edges.end(), [] (pair<int,int> &a, pair<int,int> &b) {
        return a.X * N + a.Y < b.X * N + b.Y;
    });

    solve();

    return 0;
}
