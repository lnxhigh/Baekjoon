#include <bits/stdc++.h>
using namespace std;

int N, K;
const int N_MAX = 500;

vector<int> graph[N_MAX];
bool visited[N_MAX];
int L[N_MAX], R[N_MAX];

// visited 체크 빼먹어서 그런듯...
bool dfs(int cur) {
    visited[cur] = true;

    for (int next : graph[cur]) {
        bool check = false;
        if (R[next] == -1) check = true; 
        else if (!visited[R[next]] && dfs(R[next])) check = true;

        if (check) {
            L[cur] = next;
            R[next] = cur;
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    // X -> Y 이분 그래프 빌드
    // X는 행 Y는 열로 모델링
    // 돌멩이의 위치를 간선으로 옮긴다
    // 최소 정점 커버를 구하게 되면 모든 돌멩이를 다 치우는 것과 동일하다

    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        graph[r].push_back(c);
    }

    int cnt = 0;
    fill(L, L + N, -1);
    fill(R, R + N, -1);

    for (int i = 0; i < N; i++) {
        if (L[i] != -1) continue;

        fill(visited, visited + N, false);
        bool res = dfs(i);
        if (res) cnt++; 
    }

    cout << cnt << '\n';
    return 0;
}
