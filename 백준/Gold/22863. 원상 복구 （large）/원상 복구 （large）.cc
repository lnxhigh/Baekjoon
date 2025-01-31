#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 1 << 20;

int N;
int64 K;
int S[MAX], D[MAX][20];
int P[MAX];

int L;
int len[MAX];
int visited[MAX];

int dfs(int x, int depth) {
    if (visited[x] == 1) {
        return len[x];
    }
    else if (visited[x] == 0) {
        visited[x] = 1;
        return len[x] = depth;
    }
    
    visited[x] = 0;
    len[x] = dfs(D[x][0], depth + 1);
    visited[x] = 1;
    return len[x];
}

int f(int x) {
    int newK = K % dfs(x, 0);
    for (int i = L - 1; i >= 0; i--) {
        if (newK >> i & 1) x = D[x][i];
    }
    return x;
}

int main() {
    FastIO
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> S[i];
    for (int i = 1; i <= N; i++) cin >> D[i][0];
    for (int i = N; i; i >>= 1) L++;

    for (int k = 1; k < L; k++) {
        for (int i = 1; i <= N; i++) {
            D[i][k] = D[D[i][k - 1]][k - 1];
        }
    }

    memset(visited, -1, sizeof(visited));
    for (int i = 1; i <= N; i++) dfs(i, 0);

    for (int i = 1; i <= N; i++) P[f(i)] = S[i];
    for (int i = 1; i <= N; i++) cout << P[i] << ' ';
    return 0;
}
