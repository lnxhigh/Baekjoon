#include <bits/stdc++.h>
#define K_MAX 17
#define N_MAX 100001
using namespace std;

int N, M;
vector<int> tree[N_MAX];
int depth[N_MAX];
int parent[N_MAX][K_MAX];
bool visited[N_MAX];

void dfs(int start) {
    for (int next : tree[start]) {
        if (visited[next]) continue;
        visited[next] = true;

        depth[next] = depth[start] + 1;
        parent[next][0] = start;
        dfs(next);
    }
}

int LCA(int A, int B) {
    // Swap
    if (depth[A] < depth[B]) {
        int tmp = A;
        A = B, B = tmp;
    }

    // 동일한 depth 가 될 때까지 끌어올린다
    int diff = depth[A] - depth[B];
    for (int k = 0; k < K_MAX; k++) {
        if (diff & (1 << k)) A = parent[A][k];
    }

    // LCA 를 탐색한다
    if (A == B) return A;

    for (int k = K_MAX-1; k >= 0; k--) {
        int newA = parent[A][k], newB = parent[B][k];
        if (newA == newB) continue;
        A = newA, B = newB;
    }

    A = parent[A][0], B = parent[B][0];
    return A;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N-1; i++) {
        int A, B;
        cin >> A >> B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }

    int root = 1;
    visited[root] = true;
    dfs(root);

    for (int k = 0; k < K_MAX-1; k++) {
        for (int i = 1; i <= N; i++) {
            parent[i][k+1] = parent[parent[i][k]][k];
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        cout << LCA(A, B) << '\n';
    }
    
    return 0;
}
