#include <bits/stdc++.h>
#define INF 1 << 20
using namespace std;

int N, M, K;
const int N_MAX = 1000;
const int MAX = 1 << 11;

const int S = (N_MAX << 1) + 1;
const int R = S + 1;
const int T = MAX - 1;

vector<int> graph[MAX];
int capacity[MAX][MAX];
int flow[MAX][MAX];

int maxFlow(int source, int sink) {
    int res = 0;
    
    while (true) {
        queue<int> q;
        int P[MAX];
        q.push(source);
        fill(P, P + MAX, -1);

        // BFS 로 증가 경로 탐색
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next : graph[cur]) {
                if (capacity[cur][next] > flow[cur][next] && P[next] == -1) {
                    q.push(next);
                    P[next] = cur;

                    if (next == sink) break;
                }
            }
        }

        // 만약 증가 경로가 존재하지 않으면 최상단 반복문 탈출
        if (P[sink] == -1) break;

        // 최대한 흘릴 수 있는 유량 찾기
        int amount = INF;
        for (int i = sink; i != source; i = P[i]) {
            int spare = capacity[P[i]][i] - flow[P[i]][i];
            amount = min(amount, spare);
        }

        // 경로 상의 모든 지점에 유량 흘리기
        for (int i = sink; i != source; i = P[i]) {
            flow[P[i]][i] += amount;
            flow[i][P[i]] -= amount;
        }

        // 최대 유량 업데이트
        res += amount;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;

    // 각 직원은 한 개의 일을 할 수 있다
    // S -> 직원으로 가는 용량 1 인 간선 빌드
    for (int i = 0; i < N; i++) {
        graph[S].push_back(i);
        graph[i].push_back(S);
        capacity[S][i] = 1;
    }

    // 벌점을 분배하여 일을 추가적으로 시킬 수 있다
    // S -> R 로 가는 용량 K 인 간선 빌드
    graph[S].push_back(R);
    graph[R].push_back(S);
    capacity[S][R] = K;

    // R -> 직원으로 가는 용량 K 인 간선 빌드
    for (int i = 0; i < N; i++) {
        graph[R].push_back(i);
        graph[i].push_back(R);
        capacity[R][i] = K;
    }

    // 직원 -> 일로 가는 용량 1 인 간선 빌드
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        for (int j = 0; j < L; j++) {
            int work;
            cin >> work;
            work += N_MAX - 1;
            graph[i].push_back(work);
            graph[work].push_back(i);
            capacity[i][work] = 1;
        }
    }

    // 일 -> T 로 가는 용량 1인 간선 빌드
    for (int i = N_MAX; i < N_MAX + M; i++) {
        graph[i].push_back(T);
        graph[T].push_back(i);
        capacity[i][T] = 1;
    }

    // 최대 유량이 최대 개수가 된다
    int res = maxFlow(S, T);
    cout << res << '\n';
    return 0;
}
