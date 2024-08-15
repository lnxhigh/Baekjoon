#include <bits/stdc++.h>
using namespace std;

struct T {
    pair<int,int> loc;
    int weight;

    bool operator>(const T &other) const {
        return weight > other.weight;
    }
};

int TC, N;
const int MAX = 1 << 7;
const int INF = 1 << 20;
int cave[MAX][MAX];
int dist[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int dijkstra(int N, int cave[MAX][MAX]) {
    fill(&dist[0][0], &dist[N-1][N-1] + 1, INF);
    dist[0][0] = 0;

    priority_queue<T, vector<T>, greater<T>> pq;
    T start = { {0,0}, 0 };
    pq.push(start);

    while (!pq.empty()) {
        int x = pq.top().loc.first;
        int y = pq.top().loc.second;
        int w = pq.top().weight;

        pq.pop();
        
        if (dist[x][y] < w) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if (dist[nx][ny] > w + cave[nx][ny]) {
                dist[nx][ny] = w + cave[nx][ny];
                T next = { {nx,ny}, dist[nx][ny] };
                pq.push(next);
            }
        }
    }

    return cave[0][0] + dist[N-1][N-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while (true) {
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> cave[i][j];
            }
        }

        int res = dijkstra(N, cave);
        cout << "Problem " << ++TC << ": " << res << "\n";
    }
    
    return 0;
}
