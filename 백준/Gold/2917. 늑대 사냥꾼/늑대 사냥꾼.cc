#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 9;

int r, c;
vector<string> arr;
int src, dst;

queue<int> q;
bool vis[MAX][MAX];

int dist[MAX][MAX];
vector<int> vec[MAX * 2];
int par[MAX * MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    else if (x < y) swap(x, y);
    
    par[x] = y;
    return true;
}

int main() {
    FastIO
    
    cin >> r >> c;
    arr.resize(r);
    for (string& line : arr) cin >> line;

    // Find closest tree

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == '+') q.push(i * c + j), vis[i][j] = true;
            else if (arr[i][j] == 'V') src = i * c + j;
            else if (arr[i][j] == 'J') dst = i * c + j;
        }
    }

    int cnt = 0;

    while (!q.empty()) {
        int len = q.size();
        while (len--) {
            int k = q.front();
            q.pop();

            int x = k / c, y = k % c;
            dist[x][y] = cnt;
            vec[cnt].emplace_back(k);

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                else if (vis[nx][ny]) continue;

                q.push(nx * c + ny);
                vis[nx][ny] = true;
            }
        }

        cnt++;
    }

    // Find maximum minimal distance

    int ans = 0;
    iota(par, par + MAX * MAX, 0);

    for (int i = r + c; i >= 0; i--) {
        ans = i;
        for (int k : vec[i]) {
            int x = k / c, y = k % c;
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                else if (dist[nx][ny] >= i) merge(k, nx * c + ny);
            }
        }

        if (find(src) == find(dst)) break;
    }

    cout << ans << '\n';
    return 0;
}
