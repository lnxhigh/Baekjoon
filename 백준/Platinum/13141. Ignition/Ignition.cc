#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 200;
const int INF = 100000000;

int V, E;
int graph[MAX][MAX];
int dist[MAX][MAX];

void Input() {
    cin >> V >> E;
    fill(&dist[0][0], &dist[V-1][V-1] + 1, INF);
    for (int i = 0; i < V; i++) dist[i][i] = 0;

    for (int i = 0; i < E; i++) {
        int S, E, L; cin >> S >> E >> L;
        --S, --E;

        dist[S][E] = min(dist[S][E], L);
        dist[E][S] = min(dist[E][S], L);

        graph[S][E] = max(graph[S][E], L);
        graph[E][S] = max(graph[E][S], L);
    }
}

void Floyd() {
    for (int k = 0; k < V; k++) {
        for (int x = 0; x < V; x++) {
            for (int y = 0; y < V; y++) {
                dist[x][y] = min(dist[x][y], dist[x][k] + dist[k][y]);
            }
        }
    }
}

double BurnEdge(int s, int i, int j) {
    int len = graph[i][j];
    int x = dist[s][i], y = dist[s][j];

    int diff = abs(x - y);
    if (diff >= len) return min(x + len, y + len);
    return min(x, y) + diff + (len - diff) / 2.0; 
}

double BurnGraph(int s) {
    double res = 0;
    for (int x = 0; x < V; x++) {
        for (int y = x; y < V; y++) {
            res = max(res, BurnEdge(s, x, y));
        }
    }
    return res;
}

double Solve() {
    double res = INF;
    for (int i = 0; i < V; i++) {
        res = min(res, BurnGraph(i));
    }
    return res;
}

int main() {
    FastIO

    Input();
    Floyd();

    cout << fixed << setprecision(1);
    cout << Solve() << '\n';

    return 0;
}
