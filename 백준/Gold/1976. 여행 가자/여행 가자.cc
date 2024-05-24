#include <bits/stdc++.h>
#define N_MAX 201
using namespace std;

int N, M;
int graph[N_MAX][N_MAX] = {0,};
int travel[N_MAX];

bool connected[N_MAX][N_MAX] = {false,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> travel[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) connected[i][j] = true;
            else connected[i][j] = (graph[i][j] > 0);
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (connected[i][k] && connected[k][j]) {
                    connected[i][j] = true;
                }
            }
        }
    }

    bool canReach = true;
    int from = travel[0] - 1;
    for (int i = 0; i < M; i++) {
        int to = travel[i] - 1;
        if (!connected[from][to]) {
            canReach = false;
        }
        from = to;
    }

    string answer = canReach ? "YES" : "NO";
    cout << answer << '\n';
    return 0;
}
