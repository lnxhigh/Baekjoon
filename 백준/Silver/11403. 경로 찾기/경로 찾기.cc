#include <iostream>
#define N_MAX 100
using namespace std;

int N;

int graph[N_MAX][N_MAX] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (graph[i][k] and graph[k][j]) {
                    graph[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0 ; i < N ; i++ ) {
        for (int j = 0 ; j < N ; j++ ) {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
   
    return 0;
}