#include <iostream>
#include <algorithm>
#define N_MAX 100
#define INF 10000
using namespace std;

int N, M, R;
int t[N_MAX+1];
int graph[N_MAX+1][N_MAX+1];
int dist[N_MAX+1][N_MAX+1];
int item[N_MAX+1] = {0,};
int answer = 0;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++) {
        cin >> t[i];
    }
    for (int a = 1; a <= N; a++) {
        for (int b = 1; b <= N; b++) {
            dist[a][b] = INF;
        }
    }
    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < R; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        dist[a][b] = l;
        dist[b][a] = l;
    }

    for (int k = 1; k <= N; k++) {
        for (int a = 1; a <= N; a++) {
            for (int b = 1; b <= N; b++) {
                dist[a][b] = min(dist[a][b], dist[a][k] + dist[k][b]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= N; k++) {
            if (dist[i][k] <= M) {
                item[i] += t[k];
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (item[i] > answer) {
            answer = item[i];
        }       
    }
    
    cout << answer << '\n';

    return 0;
}