#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 55;
const int INF = 1 << 28;

int n, k, m;
int sx, sy, ex, ey;
bool circuit[MAX][MAX];

int dist[MAX][MAX];
pair<int,int> track[MAX][MAX];
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int main() {
    FastIO
    cin >> n;
    cin >> sx >> sy >> ex >> ey;

    cin >> k >> m;
    while (m--) {
        int cnt; cin >> cnt;
        cnt <<= 1;

        vector<int> arr(cnt);
        for (int &x : arr) cin >> x;

        for (int i = 0; i + 3 < cnt; i += 2) {
            int a = arr[i], b = arr[i + 1], c = arr[i + 2], d = arr[i + 3];
            int ux = c - a, uy = d - b;

            if (ux) ux /= abs(ux);
            if (uy) uy /= abs(uy);

            int x = a, y = b;
            while (x != c || y != d) {
                circuit[x][y] = true;
                x += ux, y += uy;
            }
            circuit[x][y] = true;
        }
    }

    for (int i = 0; i < MAX; i++) {
        fill(dist[i], dist[i] + MAX, INF);
    }

    priority_queue<tuple<int,int,int>> pq;
    pq.push({ 0, sx, sy });
    dist[sx][sy] = 0;

    while (!pq.empty()) {
        auto [cost, x, y] = pq.top();
        cost = -cost;
        pq.pop();

        if (cost < dist[x][y]) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
            
            int nxt_cost = cost;
            nxt_cost += circuit[nx][ny] ? k : 1;

            if (nxt_cost < dist[nx][ny]) {
                dist[nx][ny] = nxt_cost;
                track[nx][ny] = { x, y };
                pq.push({ -nxt_cost, nx, ny });
            }
        }
    }

    // Shortest distance

    int ans = dist[ex][ey];
    ans += circuit[ex][ey] ? k : 1;
    cout << ans << '\n';

    // Obtain path

    vector<pair<int,int>> path;
    int x = ex, y = ey;

    while (x > 0 && y > 0) {
        path.push_back({ x, y });
        auto [nx, ny] = track[x][y];
        x = nx, y = ny;
    }

    vector<int> result;
    reverse(path.begin(), path.end());

    for (size_t i = 0; i < path.size(); i++) {
        if (i == 0 || i == path.size() - 1) {
            result.push_back(i);
        }
        else {
            auto [px, py] = path[i - 1];
            auto [x, y] = path[i];
            auto [nx, ny] = path[i + 1];

            bool chk = false;
            chk |= (x == px && x != nx && y != py && y == ny);
            chk |= (x != px && x == nx && y == py && y != ny);
            if (chk) result.push_back(i);
        }
    }

    // Print path
    
    cout << result.size() << ' ';

    for (int idx : result) {
        auto [x, y] = path[idx];
        cout << x << ' ' << y << ' ';
    }
    cout << '\n';

    return 0;
}
