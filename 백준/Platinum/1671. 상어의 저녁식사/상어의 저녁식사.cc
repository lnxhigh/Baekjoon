#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 50 * 2;
int shark[N_MAX][3];

vector<int> graph[N_MAX];
bool visited[N_MAX];
int A[N_MAX], B[N_MAX];

bool dfs(int cur) {
    visited[cur] = true;
    for (int next : graph[cur]) {
        bool check = false;
        if (B[next] == -1) check = true;
        else if (!visited[B[next]] && dfs(B[next])) check = true;
        
        if (check) {
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

    // 입력 처리
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < 3; k++) {
            cin >> shark[i][k];
        }
    }

    // 그래프 빌드
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            
            // X -> Y
            // X: 잡아먹는 상어. Y: 잡아먹히는 상어
            bool check = true; // 상어 i가 상어 j를 잡아먹을 수 있는지 체크
            bool same = true; // 두 상어가 동일한 능력을 가지는 경우 예외처리
            for (int k = 0; k < 3; k++) {
                int a = shark[i][k], b = shark[j][k];
                if (a < b) check = false;
                if (a != b) same = false;
            }

            if (!check) continue;
            if (!same || (same && i < j)) graph[i].push_back(j);
            // 동일한 능력을 갖는 경우 한 쪽에만 간선을 연결
        }
    }

    // 한 상어가 최대 두 개의 상어를 먹을 수 있다
    // 정점을 두 배로 늘린다
    for (int i = N; i < 2*N; i++) {
        graph[i] = graph[i-N];
    }
    N *= 2;

    // cnt는 최대 매칭의 개수
    int cnt = 0;
    fill(A, A + N, -1);
    fill(B, B + N, -1);

    // 이분 매칭 실시
    for (int i = 0; i < N; i++) {
        if (A[i] != -1) continue;
        
        fill(visited, visited + N, false);
        bool res = dfs(i);
        if (res) cnt++;
    }

    // 상어 수의 최솟값은 최대 매칭이 일어난 경우이다
    N /= 2;
    int answer = N - cnt;
    cout << answer << '\n';

    return 0;
}
