#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N, M, fuel;
int Map[20][20];

struct Passenger {
    pair<int,int> src;
    pair<int,int> dst;
};

pair<int,int> taxi;
vector<Passenger> passengers;

// Dist from (x, y) to (x', y')
int D[20][20][20][20];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void input() {
    cin >> N >> M;
    cin >> fuel;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Map[i][j];
        }
    }

    int x, y; 
    cin >> x >> y;
    --x, --y;
    taxi = { x, y };

    for (int i = 0; i < M; i++) {
        int a, b, x, y; 
        cin >> a >> b >> x >> y;
        --a, --b, --x, --y;
        pair<int,int> src = { a, b };
        pair<int,int> dst = { x, y };

        passengers.push_back({ src, dst });
    }
}

void getDist(int x, int y) {
    bool visited[20][20];
    memset(visited, 0, sizeof(visited));
    queue<pair<pair<int,int>,int>> q;
    
    pair<int,int> init = { x, y };
    q.push({ init, 0 });
    visited[x][y] = true;

    while (!q.empty()) {
        auto [cur, depth] = q.front();
        auto [cx, cy] = cur;
        D[x][y][cx][cy] = depth;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny] || Map[nx][ny]) continue;
            
            pair<int,int> nxt = { nx, ny };
            q.push({ nxt, depth + 1 });
            visited[nx][ny] = true;
        }
    }
}

void init() {
    memset(D, -1, sizeof(D));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            getDist(i, j);
        }
    }
}

void arrange() {
    auto [x, y] = taxi;

    sort(passengers.begin(), passengers.end(), [&] (const Passenger &one, const Passenger &other) {
        int a = D[x][y][one.src.first][one.src.second];
        int b = D[x][y][other.src.first][other.src.second];
        if (a == b) return one.src < other.src;
        return a < b;
    });
}

Passenger pick() {
    auto iter = passengers.begin();
    auto ret = *iter;
    passengers.erase(iter);
    return ret;
}

pair<int,int> drive(Passenger p) {
    auto [x, y] = taxi;
    auto [srcx, srcy] = p.src;
    auto [dstx, dsty] = p.dst;

    int first  = D[x][y][srcx][srcy];
    int second = D[srcx][srcy][dstx][dsty];
    if (first == -1 || second == -1) return { -1, -1 };

    return { first, second };
}

int solve() {
    for (int i = 0; i < M; i++) {
        arrange();
        Passenger p = pick();
        auto [first, second] = drive(p);

        if (first == -1 || second == -1) return -1;
        fuel -= first + second;
        if (fuel < 0) return -1;
        
        taxi = p.dst;
        fuel += second << 1;
    }

    return fuel;
}

int main() {
    FastIO
    input();
    init();
    
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
