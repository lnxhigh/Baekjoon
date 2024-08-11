#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 100;
int H[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void dfs(int x, int y, int arr[MAX][MAX]) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) continue;
        if (visited[nextX][nextY] || arr[nextX][nextY] == -1) continue;
        dfs(nextX, nextY, arr);
    }
}

int countSafeZone(int arr[MAX][MAX]) {
    fill(&visited[0][0], &visited[N-1][N-1]+1, false);
    int res = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == -1) continue;
            if (visited[i][j]) continue;
            dfs(i, j, arr);
            res++;
        }
    }
    
    return res;
}

int simulate(int h) {
    int arr[MAX][MAX];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int value = (H[i][j] <= h) ? -1 : H[i][j];
            arr[i][j] = value;
        }
    }

    int res = countSafeZone(arr);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    int maxH = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> H[i][j];
            maxH = max(maxH, H[i][j]);
        }
    }

    int res = 0;
    for (int h = 0; h <= maxH; h++) {
        int tmp = simulate(h);
        res = max(res, tmp);
    }

    cout << res << '\n';
    return 0;
}
