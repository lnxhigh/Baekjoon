#include <iostream>
#include <queue>
#define N_MAX 801
#define INF 100000000
using namespace std;

int N, E;
int graph[N_MAX][N_MAX];
int v1, v2;

int dist_0 [N_MAX];
int dist_v1[N_MAX];
int dist_v2[N_MAX];
int dist_N [N_MAX];

void dijkstra(int start, int distance[]) {
    priority_queue<int> pq;

    for (int i = 1; i <= N; i++) {
        distance[i] = INF;
    }
    distance[start] = 0;
    pq.push(start);

    while (not pq.empty()) {
        int cur = pq.top();
        pq.pop();

        for (int next = 1; next <= N; next++) {
            if (graph[cur][next] >= INF) continue;

            if (distance[next] > distance[cur] + graph[cur][next]) {
                distance[next] = distance[cur] + graph[cur][next];
                pq.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> E;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }
    for (int e = 0; e < E; e++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }    
    cin >> v1 >> v2;

    dijkstra(1, dist_0);
    dijkstra(v1, dist_v1);
    dijkstra(v2, dist_v2);
    dijkstra(N, dist_N);
    
    int answer;
    int ans1, ans2;
    ans1 = dist_0[v1] + dist_v1[v2] + dist_v2[N];
    ans2 = dist_0[v2] + dist_v2[v1] + dist_v1[N];
    answer = (ans1 < ans2) ? ans1 : ans2;
    
    if (answer >= INF) answer = -1;
    cout << answer << '\n';

    return 0;
}