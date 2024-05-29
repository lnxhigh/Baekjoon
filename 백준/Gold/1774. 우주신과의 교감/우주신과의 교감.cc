#include <bits/stdc++.h>
#define N_MAX 1000
#define X first
#define Y second
using namespace std;
using Point = pair<int,int>;

int N, M;

typedef struct Edge {
    pair<int,int> p;
    double cost;
} Edge;

vector<Point> points;
vector<Edge> edges;
bool connected[N_MAX][N_MAX];

int parent[N_MAX+1];

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

double dist(const Point &A, const Point &B) {
    double dx = (double) A.X - (double) B.X;
    double dy = (double) A.Y - (double) B.Y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    points.reserve(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({ x, y });
    }

    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        connected[x-1][y-1] = connected[y-1][x-1] = true;
    }

    edges.reserve(N*N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            pair<int,int> p = { i, j };
            double cost = connected[i][j] ? 0.0 : dist(points[i], points[j]);
            edges.push_back({ p, cost });
        }
    }

    sort(edges.begin(), edges.end(), [] (Edge &left, Edge &right) {
        return left.cost < right.cost;
    });

    double answer = 0.0;
    for (Edge edge : edges) {
        bool res = merge(edge.p.X, edge.p.Y);
        if (res) answer += edge.cost;
    }

    cout << fixed << setprecision(2) << answer << '\n';
    return 0;
}
