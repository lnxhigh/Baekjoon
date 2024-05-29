#include <bits/stdc++.h>
#define MAX 10
#define X first
#define Y second
using namespace std;
using Point = pair<int,int>;

int R, C;
int country[MAX][MAX];

bool visited[MAX][MAX];
int component = 0;
vector<Point> group[MAX*MAX];

typedef struct Edge {
    pair<int,int> p;
    int cost;
} Edge;
vector<Edge> edges;

int parent[MAX*MAX];

// 섬의 그룹 판별

void BFS(Point start) {
    queue<Point> q;
    q.push(start);
    visited[start.X][start.Y] = true;

    // Up Down Left Right
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        Point cur = q.front();
        group[component].push_back(cur);
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.X + dr[i];
            int y = cur.Y + dc[i];
            if (x < 0 || x >= R || y < 0 || y >= C) continue;
            if (visited[x][y]) continue;
            if (country[x][y] == 0) continue;

            visited[x][y] = true;
            Point next = { x, y };
            q.push(next);
        }

    }
}

// Edge 건설

void build(Point p) {
    int x = p.first, y = p.second;
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    for (int i = 0; i < 4; i++) {
        int nextX = x, nextY = y;
        while (true) {
            nextX += dr[i];
            nextY += dc[i];
            if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) break;

            int a = country[x][y];
            int b = country[nextX][nextY];
            if (a == b) break;
            else if (b > 0) {
                int dx = nextX - x;
                int dy = nextY - y;
                int cost = abs(dx) + abs(dy) - 1;
                if (cost >= 2) {
                    pair<int,int> p = { a, b };
                    edges.push_back({ p, cost });
                } 
                break;
            }
        }
    }
}

// MST 알고리즘

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;

    if (x > y) parent[x] = y;
    else       parent[y] = x;
    return true;
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> country[i][j];
        }
    }

    // 섬의 그룹 판별

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!visited[i][j] && country[i][j]) {
                BFS({i, j});
                component++;
            }
        }
    }
    for (int curGroup = 0; curGroup < component; curGroup++) {
        for (Point p : group[curGroup]) {
            country[p.X][p.Y] = curGroup + 1;
        }
    }

    // Edge 건설

    for (int curGroup = 0; curGroup < component; curGroup++) {
        for (Point p : group[curGroup]) {
            build(p);
        }
    }
    sort(edges.begin(), edges.end(), [] (Edge &left, Edge &right) {
        return left.cost < right.cost;
    });

    // MST 알고리즘

    int cnt = 0;
    int value = 0;
    for (int i = 1; i <= component; i++) {
        parent[i] = i;
    }

    for (Edge edge : edges) {
        bool res = merge(edge.p.X, edge.p.Y);
        if (res) {
            cnt++;
            value += edge.cost;
        }
    }

    int answer = (cnt == component - 1) ? value : -1;
    cout << answer << '\n';

    return 0;
}
