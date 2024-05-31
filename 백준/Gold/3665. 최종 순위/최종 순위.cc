#include <bits/stdc++.h>
#define N_MAX 501
using namespace std;

int T;
int A[N_MAX];
bool graph[N_MAX][N_MAX];
int inDegree[N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        // Initialize
        fill(A, A + N_MAX, 0);
        fill(&graph[0][0], &graph[N_MAX-1][N_MAX-1] + 1, 0);
        fill(inDegree, inDegree + N_MAX, 0);

        // Build Graph
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }
        for (int i = 1; i <= N; i++) {
            for (int j = i+1; j <= N; j++) {
                graph[A[i]][A[j]] = true;
            }
        }

        int M;
        cin >> M;
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            graph[a][b] = !graph[a][b];
            graph[b][a] = !graph[b][a];
        }

        // Topological Sort
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (graph[i][j]) inDegree[j]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= N; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        bool isImpossible = false;
        bool isAmbiguous = false;
        vector<int> res;
        res.reserve(N);

        for (int i = 0; i < N; i++) {
            if (q.empty()) {
                isImpossible = true;
                break;
            }
            
            if (q.size() >= 2) {
                isAmbiguous = true;
            }

            int cur = q.front();
            q.pop();
            res.push_back(cur);

            for (int next = 1; next <= N; next++) {
                if (graph[cur][next]) {
                    inDegree[next]--;
                    if (inDegree[next] == 0) q.push(next);
                }
            }
        }

        if (isImpossible) {
            cout << "IMPOSSIBLE" << '\n';
        }
        else if (isAmbiguous) {
            cout << "?" << '\n';
        }
        else {
            for (int i : res) cout << i << ' ';
            cout << '\n';
        }
    }

    return 0;
}
