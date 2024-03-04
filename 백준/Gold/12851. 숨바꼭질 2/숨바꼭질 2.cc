#include <iostream>
#include <utility>
#include <queue>
#define N_MAX 100000

using namespace std;
int N, K;

void bfs(int N, int K) {
    queue<pair<int,int>> q;
    int visited[N_MAX+1] = {0,};
    int max_depth = N_MAX;
    int cnt = 0;
    q.push({N, 0});

    while (not q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();
        visited[cur]++;

        if (depth > max_depth) break;
        if (cur == K) {
            max_depth = depth;
            cnt++;
        }

        for (int next : { cur+1, cur-1, 2*cur }) {
            if (next < 0 || next > N_MAX) continue;
            if (visited[next]) continue;
            q.push({ next, depth+1 });
        }
    }
    
    cout << max_depth << '\n';
    cout << cnt << '\n';
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> K;
    bfs(N, K);
    
    return 0;
}