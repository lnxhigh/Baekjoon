#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;

int N, M;
int A, B;
vector<int> graph[MAX];
int inDegree[MAX] = {0,};
int height[MAX] = {0,};
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        graph[A].push_back(B);
        inDegree[B]++;
    }

    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    for (int i = 0; i < N; i++) {
        if (q.empty()) {
            cout << "graph has a cycle" << '\n';
            return 0;
        }

        int x = q.front();
        height[i] = x;
        q.pop();

        for (int k : graph[x]) {
            inDegree[k]--;
            if (inDegree[k] == 0) {
                q.push(k);
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << height[i] << ' ';
    }
    
    return 0;
}