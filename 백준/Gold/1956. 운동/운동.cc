#include <bits/stdc++.h>
#define INF 1000000000
#define V_MAX 401
using namespace std;

int V, E;
int dist[V_MAX][V_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;

    fill(&dist[0][0], &dist[V_MAX-1][V_MAX-1] + 1, INF);
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }

    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int answer = INF;
    for (int i = 1; i <= V; i++) {
        answer = min(answer, dist[i][i]);
    }
    answer = (answer >= INF) ? -1 : answer;
    cout << answer << '\n';

    return 0;
}
