#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 501;

vector<int> graph[N_MAX];
int C[N_MAX], D[N_MAX];
int inDegree[N_MAX];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력 처리 및 그래프 빌드
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> C[i];

        int X;
        while (true) {
            cin >> X;
            if (X == -1) break;
            graph[X].push_back(i);
            inDegree[i]++;
        }
    }

    // 위상 정렬
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {
            D[i] += C[i];
            q.push(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            D[next] = max(D[next], D[cur] + C[next]);
            if (--inDegree[next] == 0) {
                q.push(next);
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= N; i++) {
        cout << D[i] << '\n';
    }

    return 0;
}
