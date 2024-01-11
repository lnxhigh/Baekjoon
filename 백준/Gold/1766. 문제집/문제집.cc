#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int A, B;
vector<int> graph[32001];
int inDegree[32001] = {0,};
priority_queue<int,vector<int>, greater<int>> pq;
queue<int> answer;

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
            pq.push(i);
        }
    }

    for (int i = 0; i < N; i++) {
        if (pq.empty()) {
            cout << "The graph has a cycle." << '\n';
            return 1;
        }
        
        int x = pq.top();
        answer.push(x);
        pq.pop();
        for (int k : graph[x]) {
            if (--inDegree[k] == 0) {
                pq.push(k);
            }
        }
    }

    if (not pq.empty()) {
        cout << "Error" << '\n';
    }

    for (int i = 0; i < N; i++) {
        cout << answer.front() << ' ';
        answer.pop();
    }
    if (not answer.empty()) {
        cout << "Answer is not empty" << '\n';
    }

    return 0;
}