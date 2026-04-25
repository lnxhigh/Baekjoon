#include <iostream>
#define N_MAX 100
#define INF 1000000000
using namespace std;

int N, M;
int a, b, c;
int city[N_MAX+1][N_MAX+1] = {0,};
int cost[N_MAX+1][N_MAX+1] = {0,};
int Min(int x, int y) { return x < y ? x : y ; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if (not city[a][b]) city[a][b] = c;
        else city[a][b] = Min(city[a][b], c);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) cost[i][j] = 0;
            else if (city[i][j]) cost[i][j] = city[i][j];
            else cost[i][j] = INF;
        }
    }

    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                cost[i][j] = Min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (cost[i][j] == INF) cost[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
