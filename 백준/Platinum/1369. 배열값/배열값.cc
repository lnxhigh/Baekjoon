#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1001;
const int INF = 1 << 20;

int n;
bool zero[MAX][MAX];
int arr[2][MAX][MAX];

int dist[2][MAX][MAX];
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

int dijkstra(bool f) {
    priority_queue<pair<int,int>> pq;
    pq.push({ -arr[f][0][0], 0 });
    dist[f][0][0] = arr[f][0][0];
    
    while (!pq.empty()) {
        auto [cost, k] = pq.top();
        int x = k / n, y = k % n;
        cost = -cost;
        pq.pop();

        if (dist[f][x][y] < cost) continue;

        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            else if (zero[nx][ny]) continue;

            int nxt_cost = cost + arr[f][nx][ny];

            if (nxt_cost < dist[f][nx][ny]) {
                dist[f][nx][ny] = nxt_cost;
                pq.push({ -nxt_cost, n * nx + ny });
            }
        }
    }

    return dist[f][n - 1][n - 1];
}

int main() {
    FastIO
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            dist[0][i][j] = dist[1][i][j] = INF;

            if (x == 0) {
                zero[i][j] = true;
            }
            else {
                while (x % 2 == 0) x /= 2, arr[0][i][j]++;
                while (x % 5 == 0) x /= 5, arr[1][i][j]++;
            }
        }
    }

    // Dijkstra

    int ans = min(dijkstra(true), dijkstra(false));
    cout << ans << '\n';
    return 0;
}
