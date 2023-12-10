#include <iostream>
#define N_MAX 101
#define INF 101
using namespace std;

int N, M;
int answer = 1;
int graph[N_MAX][N_MAX];
int dist[N_MAX][N_MAX];
int result[N_MAX];
int Min(int x, int y) { return x < y ? x : y ; }

void input(int& N, int& M, int graph[N_MAX][N_MAX], int dist[N_MAX][N_MAX]) {   
    cin >> N >> M;

    for (int i = 0; i < N_MAX; i++) {
        for (int j = 0; j < N_MAX; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[A][B] = 1;
        graph[B][A] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) dist[i][j] = 0;
            else if (graph[i][j] > 0) dist[i][j] = graph[i][j];
            else dist[i][j] = INF;
        }
    }
}

void Floyd_Warshall(int N, int dist[N_MAX][N_MAX]) {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = Min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void Kevin_Bacon(int N, int dist[N_MAX][N_MAX], int arr[N_MAX]) {
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            sum += dist[i][j];
        }
        arr[i] = sum;
    }
}

void Min_index(int N, int arr[N_MAX], int& x) {
    int temp = (1 << 30);
    for (int i = 1; i <= N; i++) {
        if (temp > arr[i]) {
            x = i;
            temp = arr[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    input(N, M, graph, dist);
    Floyd_Warshall(N, dist);
    Kevin_Bacon(N, dist, result);
    Min_index(N, result, answer);
    cout << answer << '\n';

    return 0;
}