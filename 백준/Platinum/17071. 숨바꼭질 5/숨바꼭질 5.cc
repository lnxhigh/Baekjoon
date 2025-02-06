#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 500001;

int N, K;
bool vis[MAX][2];

// 논리가 완벽하지 않은 것 같다
int bfs(int src, int dst) {
    queue<pair<int,int>> q;
    q.push({ src, 0 });
    vis[src][0] = true;
    
    while (!q.empty()) {
        auto [x, t] = q.front();
        q.pop();

        int y = dst + t*(t+1)/2;
        if (y >= MAX) break;
        else if (vis[y][t&1]) return t;

        for (int nxt : { x-1, x+1, x<<1 }) {
            if (nxt < 0 || nxt > MAX) continue;
            else if (vis[nxt][(t+1)&1]) continue;

            q.push({ nxt, t+1 });
            vis[nxt][(t+1)&1] = true;
        }
    }
    
    return -1;
}

int main() {
    FastIO
    cin >> N >> K;
    cout << bfs(N, K) << '\n';
    return 0;
}
