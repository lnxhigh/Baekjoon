#include <iostream>
using namespace std;

int T;
int M, N, K;
int X, Y;
bool cabbage[50][50] = {false,};
bool visit[50][50] = {false,};

bool isValid(int x, int y, int M, int N) {
    if (x < 0 or x >= M) return false;
    if (y < 0 or y >= N) return false;
    if (visit[x][y]) return false;

    return true;
}

void dfs(int x, int y, int M, int N) {
    if (isValid(x+1, y, M, N)) {
        visit[x+1][y] = true;
        if (cabbage[x+1][y]) dfs(x+1, y, M, N);
    }
    if (isValid(x-1, y, M, N)) {
        visit[x-1][y] = true;
        if (cabbage[x-1][y]) dfs(x-1, y, M, N);
    }    
    if (isValid(x, y+1, M, N)) {
        visit[x][y+1] = true;
        if (cabbage[x][y+1]) dfs(x, y+1, M, N);
    }    
    if (isValid(x, y-1, M, N)) {
        visit[x][y-1] = true;
        if (cabbage[x][y-1]) dfs(x, y-1, M, N);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> M >> N >> K;

        int component = 0;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cabbage[i][j] = false;
                visit[i][j] = false;
            }
        }
        
        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            cabbage[X][Y] = true;
        }
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (not visit[i][j]) {
                    visit[i][j] = true;

                    if (cabbage[i][j]) {
                        
                        component++;
                        dfs(i, j, M, N);
                    }
                }
            }
        }

        cout << component << '\n';
        
    }
    
    return 0;
}