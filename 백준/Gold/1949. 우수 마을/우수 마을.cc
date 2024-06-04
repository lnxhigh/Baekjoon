#include <bits/stdc++.h>
#define N_MAX 10001
using namespace std;

int N;
vector<int> tree[N_MAX];
int W[N_MAX];
int D[2][N_MAX];
bool visited[N_MAX];

void dfs(int parent) {
    for (int child : tree[parent]) {
        if (visited[child]) continue;
        visited[child] = true;
        dfs(child);

        D[0][parent] += max(D[0][child], D[1][child]);
        D[1][parent] += D[0][child];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> W[i];
        D[1][i] += W[i];
    }
    for (int i = 0; i < N-1; i++) {
        int A, B;
        cin >> A >> B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }

    int root = 1;
    visited[root] = true;
    dfs(root);

    int answer = max(D[0][root], D[1][root]);
    cout << answer << '\n';
    
    return 0;
}
