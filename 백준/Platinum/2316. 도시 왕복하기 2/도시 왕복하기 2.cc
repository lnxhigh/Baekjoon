#include <bits/stdc++.h>
using namespace std;

int V, E;
const int V_MAX = 801;
const int E_MAX = 10000;
const int S = 1, T = 2;

vector<int> graph[V_MAX];
int capacity[V_MAX][V_MAX];
int flow[V_MAX][V_MAX];

int in (int k) { return 2 * k; }
int out(int k) { return 2 * k - 1; }

int maxFlow(int source, int sink) {
    int res = 0;
    while (true) {
        queue<int> q;
        q.push(source);
        int P[V_MAX];
        fill(P, P + V_MAX, -1);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (P[sink] != -1) break;

            for (int next : graph[cur]) {
                if (capacity[cur][next] > flow[cur][next] && P[next] == -1) {
                    q.push(next);
                    P[next] = cur;
                    if (next == sink) break;
                }
            }
        }

        // 증가 경로가 없으면 종료
        if (P[sink] == -1) break;

        // 증가 경로가 존재하면 유량을 흘려 준다
        int amount = 1 << 20;
        for (int i = sink; i != source; i = P[i]) {
            int spare = capacity[P[i]][i] - flow[P[i]][i];
            amount = min(amount, spare);
        }

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

    // 하나의 노드를 두 개로 분리
    // 2X-1 => 나가는 노드
    // 2X   => 들어오는 노드
    for (int i = 0; i < E; i++) {
        int X, Y;
        cin >> X >> Y;
        
        // 양방향 간선 연결 => 각각을 단방향으로 연결
        vector<pair<int,int>> V = {{ X, Y }, { Y, X }};
        for (pair<int,int> p : V) {
            int newX = out(p.first), newY = in(p.second);
            graph[newX].push_back(newY);
            graph[newY].push_back(newX);
            capacity[newX][newY] = 1;
        }
    }

    // 정점 내부의 단방향 간선 연결
    for (int i = 1; i <= V; i++) {
        int X = in(i), Y = out(i);
        graph[X].push_back(Y);
        graph[Y].push_back(X);
        capacity[X][Y] = 1;
    }

    int res = maxFlow(out(S), in(T));
    cout << res;
    return 0;
}
