#include <bits/stdc++.h>
#define N_MAX 100001
using namespace std;

int N, K;
int visited[N_MAX];
int P[N_MAX];

int BFS(int N, int K) {
    queue<pair<int,int>> q;
    q.push({ N, 0 });
    visited[N]++;

    while (!q.empty()) {
        int X = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (X == K) return depth;

        for (int next : { X << 1, X + 1, X - 1 }) {
            if (next < 0 || next >= N_MAX) continue;
            if (visited[next]++) continue;
            q.push({ next, depth+1 });
            P[next] = X;
        }
    }

    return -1;
}

int main() {
    cin >> N >> K;
    int answer = BFS(N, K);
    cout << answer << '\n';

    vector<int> path;
    for (int i = K; i != N; i = P[i]) path.push_back(i);
    path.push_back(N);
    reverse(path.begin(), path.end());
    for (int i : path) cout << i << ' '; 
    cout << '\n';

    return 0;
}
