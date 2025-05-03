#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int INF = 1 << 20;

int m, n, l;
int town[32];

int edge[251][251];
vector<int> faces[251];

bool adj[251][251];
int dist[251][251];

int main() {
    FastIO

    // Input

    cin >> m >> n >> l;
    for (int i = 1; i <= l; i++) {
        cin >> town[i];
    }

    for (int f = 1; f <= m; f++) {
        int cnt; cin >> cnt;
        vector<int> vec(cnt);

        for (int& v : vec) {
            cin >> v;
            faces[v].push_back(f);
        }

        for (int i = 0; i < cnt; i++) {
            int x = vec[i], y = vec[(i + 1) % cnt];

            if (edge[x][y] || edge[y][x]) {
                int other = edge[x][y];
                adj[f][other] = adj[other][f] = true;
            }
            else {
                edge[x][y] = edge[y][x] = f;
            }
        }
    }

    // Floyd

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x = (i == j) ? 0 : adj[i][j] ? 1 : INF;
            dist[i][j] = x;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = INF;
    int idx = -1;

    for (int i = 1; i <= m; i++) {
        int sum = 0;

        for (int j = 1; j <= l; j++) {
            int cnt = INF;
            for (int f : faces[town[j]]) {
                cnt = min(cnt, dist[f][i]);
            }
            sum += cnt;
        }

        if (sum < ans) {
            ans = sum;
            idx = i;
        }
    }

    cout << ans << '\n';
    cout << idx << '\n';

    return 0;
}
