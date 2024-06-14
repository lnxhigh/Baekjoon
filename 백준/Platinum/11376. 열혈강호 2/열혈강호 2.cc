#include <bits/stdc++.h>
using namespace std;

int N, M;
const int N_MAX = 2001;
int A[N_MAX], B[N_MAX];

vector<int> graph[N_MAX];
bool visited[N_MAX];

bool dfs(int cur) {
    visited[cur] = true;
    for (int next : graph[cur]) {
        if (visited[B[next]]) continue;
        if (!B[next] || dfs(B[next])) {
            A[cur] = next;
            B[next] = cur;
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int L;
        cin >> L;
        for (int j = 0; j < L; j++) {
            int W;
            cin >> W;

            // 사람의 수를 두 배로 늘린다
            graph[2*i-1].push_back(W);
            graph[ 2*i ].push_back(W);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N * 2; i++) {
        if (A[i]) continue;
        fill(visited, visited + N * 2 + 1, false);
        bool res = dfs(i);
        if (res) cnt++;
    }

    cout << cnt << '\n';
    return 0;
}
