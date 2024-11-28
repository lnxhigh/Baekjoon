#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 50;
const int INF = 1 << 20;

int N;
int graph[MAX][MAX];
int D[MAX][MAX];
int X[MAX];

void input() {
    cin >> N;
    while (true) {
        int x, y; cin >> x >> y;
        if (x < 0 && y < 0) break;
        --x, --y;
        graph[x][y] = graph[y][x] = true;
    }
}

void Floyd() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) D[i][j] = 0;
            else if (graph[i][j]) D[i][j] = 1;
            else D[i][j] = INF;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
}

void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X[i] = max(X[i], D[i][j]);
        }
    }

    int value = *min_element(X, X + N);
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        if (X[i] == value) cnt++;
    }

    cout << value << ' ' << cnt << '\n';
    for (int i = 0; i < N; i++) {
        if (X[i] == value) cout << i + 1 << ' ';
    }
    cout << '\n';

    return;
}

int main() {
    FastIO
    input();
    Floyd();
    print();
    return 0;
}
