#include <bits/stdc++.h>
#define V_MAX 101
#define INF 1000000000
using namespace std;

// 가능한 경로가 여러 개임 ...

int V, E;
int cost[V_MAX][V_MAX];
int P[V_MAX][V_MAX];

void f(int start, int end, vector<int> &path) {
    int mid = P[start][end];
    if (mid == 0) {
        path.push_back(start);
        path.push_back(end);
        return;
    }
    
    f(start, mid, path);
    path.pop_back();
    f(mid, end, path);
}

int main() {
    cin >> V >> E;
    fill(&cost[1][1], &cost[V][V] + 1, INF);
    for (int i = 1; i <= V; i++) cost[i][i] = 0;
    
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (cost[a][b] > c) { cost[a][b] = c; }
    }

    // 플로이드 알고리즘
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (cost[i][j] > cost[i][k] + cost[k][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                    P[i][j] = k;
                }
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (cost[i][j] >= INF) cost[i][j] = 0;
        }
    }
    
    // 최소 비용 출력
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            cout << cost[i][j] << " ";
        }
        cout << "\n";
    }

    // 경로 출력
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (cost[i][j] == 0) {
                cout << 0 << '\n';
                continue;
            }

            vector<int> path;            
            f(i, j, path);

            int k = path.size();
            cout << k << ' ';
            for (int p : path) cout << p << ' ';
            cout << '\n';
        }
    }

    return 0;
}
