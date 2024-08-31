#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

struct Info { int x, y, r; };
struct Edge { int from, to; double cost; };

int N;
const int MAX = 1 << 10;
Info gears[MAX];
vector<Edge> edges;

int parent[MAX];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;

    if (x > y) parent[x] = y;
    else parent[y] = x;
    return true;
}

double MST() {
    iota(parent, parent + N + 1, 0);
    sort(edges.begin(), edges.end(), [] (Edge &A, Edge &B) {
        return A.cost < B.cost;
    });

    double res = 0;
    for (const Edge &edge : edges) {
        bool isMerged = merge(edge.from, edge.to);
        if (isMerged) res += edge.cost;
    }

    return res;
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        gears[i] = { x, y, r };
    }

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int dx = gears[i].x - gears[j].x;
            int dy = gears[i].y - gears[j].y;
            int dr = gears[i].r - gears[j].r;

            int dd = dx*dx + dy*dy;
            int r = gears[i].r + gears[j].r;

            if (dd <= r*r) {
                double cost = 0;
                Edge edge = { i, j, cost };
                edges.push_back(edge);
            }
            else {
                double d = sqrt(dd);
                double val = abs(dr) / d;
                double theta = asin(val);

                double small = min(gears[i].r, gears[j].r) * (M_PI - theta * 2);
                double large = max(gears[i].r, gears[j].r) * (M_PI + theta * 2);
                double mid = sqrt(dd - dr*dr) * 2;
                
                double cost = small + large + mid;
                Edge edge = { i, j, cost };
                edges.push_back(edge);
            }
        }
    }

    double res = MST();
    cout << setprecision(16);
    cout << res << '\n';
    return 0;
}
