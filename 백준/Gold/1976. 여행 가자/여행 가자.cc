#include <bits/stdc++.h>
#define N_MAX 201
using namespace std;

int N, M;
int graph[N_MAX][N_MAX] = {0,};
int travel[N_MAX];

int parent[N_MAX];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (x > y) parent[x] = y;
    else       parent[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x;
            cin >> x;
            if (x > 0) merge(i, j);
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> travel[i];
    }

    bool canReach = true;
    int root = find(travel[0]);
    for (int i = 0; i < M; i++) {
        if (find(travel[i]) != root) canReach = false;
    }
    string answer = canReach ? "YES" : "NO";
    cout << answer << '\n';

    return 0;
}
