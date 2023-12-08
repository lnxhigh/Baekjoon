#include <iostream>
#include <vector>
#define INF 1000000000
#define N_MAX 501
#define M_MAX 2501
#define W_MAX 201
using namespace std;

int T;
int Min(int x, int y) { return x < y ? x : y ; }

void input(int graph[N_MAX][N_MAX], int &N, int&M, int&W) {
    int S, E, T;
    
    cin >> N >> M >> W;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            graph[i][j] = INF;
        }
    }

    for (int i = 1; i <= N; i++) {
        graph[i][i] = 0;
    }

    for (int i = 0; i < M; i++) {
        cin >> S >> E >> T;
        graph[S][E] = Min(graph[S][E], T);
        graph[E][S] = Min(graph[E][S], T);
    }

    for (int i = 0; i < W; i++) {
        cin >> S >> E >> T;
        graph[S][E] = Min(graph[S][E], -T);
    }
}

void bellman_ford(int graph[N_MAX][N_MAX], int dist[], int N, int M, int W) {
    int start = 1;
    for (int i = 1; i <= N; i++) dist[i] = INF;
    dist[start] = 0;

    for (int k = 0; k < N-1; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int from = i, to = j, weight = graph[i][j];
                if (dist[to] > dist[from] + weight) {
                    dist[to] = dist[from] + weight;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, M, W;
        
        int graph[N_MAX][N_MAX];
        int dist[N_MAX];

        input(graph, N, M, W);
        bellman_ford(graph, dist, N, M, W);
        

        bool cycle = false;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int from = i, to = j, weight = graph[i][j];
                if (dist[to] > dist[from] + weight) {
                    cycle = true;
                }
            }
        }

        if (cycle) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}