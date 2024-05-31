#include <bits/stdc++.h>
using namespace std;

int N, M;
bool visited[101];
int snake[101];
int ladder[101];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ladder[x] = y;
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        snake[x] = y;
    }

    queue<pair<int,int>> q;
    q.push({1, 0});
    visited[1] = true;

    int answer = 0;
    while (!q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (cur == 100) {
            answer = depth;
            break;
        }

        for (int i = 1; i <= 6; i++) {
            int next = cur + i;
            if (next > 100) continue;
            if (visited[next]) continue;
            visited[next] = true;

            if (snake[next])  next = snake[next];
            if (ladder[next]) next = ladder[next];
            q.push({ next, depth+1 });
        }
    }

    cout << answer << '\n';
    return 0;
}
