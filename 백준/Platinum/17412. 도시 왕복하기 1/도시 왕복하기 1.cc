#include <bits/stdc++.h>
#define INF 1 << 20
using namespace std;

const int N_MAX = 401;
const int S = 1, T = 2;

int V, E;
vector<int> graph[N_MAX];
int capacity[N_MAX][N_MAX];
int flow[N_MAX][N_MAX];

int maxFlow(int source, int sink) {
    int res = 0;

    while (true) {
        queue<int> q;
        int P[N_MAX];
        fill(P, P + N_MAX, -1);
        q.push(source);

        // BFS 를 사용하여 sink 까지 가는 경로 탐색 및 저장
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next : graph[cur]) {
                // 아직 방문하지 않았으며 흘릴 수 있는 유량이 남아 있을 때 다음 지점으로 선택
                if (capacity[cur][next] > flow[cur][next] && P[next] == -1) {
                    q.push(next);
                    P[next] = cur;
                    if (next == sink) break;
                }
            }
        }

        // sink 까지 도달 가능한 경로가 없으면 종료
        if (P[sink] == -1) break;

        // 해당 경로에 대해 흘릴 수 있는 최대한의 유량을 구한다
        int amount = INF;
        for (int i = sink; i != source; i = P[i]) {
            int spare = capacity[P[i]][i] - flow[P[i]][i];
            amount = min(amount, spare);
        }

        // 해당 경로에 유량을 추가한다
        for (int i = sink; i != source; i = P[i]) {
            flow[P[i]][i] += amount;
            flow[i][P[i]] -= amount;
        }
        
        res += amount;
    }
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int X, Y;
        cin >> X >> Y;
        graph[X].push_back(Y);
        graph[Y].push_back(X);
        capacity[X][Y] = 1;
    }

    int res = maxFlow(S, T);
    cout << res << '\n';
    return 0;
}
