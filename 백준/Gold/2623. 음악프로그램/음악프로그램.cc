#include <iostream>
#include <vector>
#include <queue>
#define N_MAX 1000
using namespace std;

int N, M;
int k, from, to;
vector<int> graph[N_MAX+1];
int inDegree[N_MAX+1] = {0,};
queue<int> q;
vector<int> answer;
bool possible = true;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        from = 0;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> to;
            graph[from].push_back(to);
            from = to;
            inDegree[to]++;
        }
    }

    for (int i = 0; i <= N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    for (int i = 0; i <= N; i++) {
        if (q.empty()) { // graph has a cycle
            possible = false;
            break;
        }

        k = q.front();
        answer.push_back(k);
        q.pop();
        for (int x : graph[k]) {
            if (--inDegree[x] == 0) q.push(x);
        }
    }

    if (not possible) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        cout << answer[i] << '\n';
    }
    return 0;
}