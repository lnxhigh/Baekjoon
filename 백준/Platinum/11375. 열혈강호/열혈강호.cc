#include <bits/stdc++.h>
using namespace std;

int N, M;
const int N_MAX = 1001;
vector<int> graph[N_MAX];

int A[N_MAX];
int B[N_MAX];
bool visited[N_MAX];

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int L;
        cin >> L;
        for (int j = 0; j < L; j++) {
            int W;
            cin >> W;
            graph[i].push_back(W);
        }
    }
}

// 매칭이 성공하면 true 반환
// 각 노드마다 최대 E 번을 확인
// O(VE) 의 시간복잡도가 된다

// 이미 매칭이 된 상태면
// 기존에 매칭을 한 사람이 다른 매칭을 할 수 있는지 모두 검사한다
// 다른 매칭이 존재한다면 기존의 매칭을 뺏는다

// visited[B[next]] == true 가 되는 경우
// 이 경우는 dfs(B[next]) == false 인 상태를 전제하는 것으로 이해함
// 어차피 B[next] 의 매칭을 다른 걸로 바꿔도 유효한 매칭이 없으므로 건너뛴다

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
    input();

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i]) continue;
        fill(visited, visited + N + 1, false);
        if (dfs(i)) answer++;
    }

    cout << answer << '\n';
    return 0;
}
