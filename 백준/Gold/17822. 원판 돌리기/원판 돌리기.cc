#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
int N, M, T;
int Circle[50][50];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

vector<pair<int,int>> bfs(int x, int y, bool visited[50][50]) {
    vector<pair<int,int>> ret;

    queue<pair<int,int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty()) {
        ret.push_back(q.front());
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = (cy + dy[i] + M) % M;
            if (nx < 0 || nx >= N) continue;
            if (Circle[nx][ny] == -1 || visited[nx][ny]) continue;
            if (Circle[cx][cy] != Circle[nx][ny]) continue;

            q.push({ nx, ny });
            visited[nx][ny] = true;
        }
    }

    return ret;
}

vector<vector<pair<int,int>>> find() {
    vector<vector<pair<int,int>>> ret;
    bool visited[50][50];
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Circle[i][j] == -1 || visited[i][j]) continue;
            auto group = bfs(i, j, visited);
            if ((int) group.size() > 1) {
                ret.push_back(group);
            }
        }
    }

    return ret;
}

void erase(const vector<vector<pair<int,int>>> &groups) {
    for (auto &group : groups) {
        for (auto [x, y] : group) {
            Circle[x][y] = -1;
        }
    }
}

void adjust() {
    int sum = 0;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Circle[i][j] != -1) {
                sum += Circle[i][j];
                cnt ++;
            }
        }
    }

    if (cnt == 0) return;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Circle[i][j] == -1) continue;
            
            if      (Circle[i][j] * cnt > sum) Circle[i][j]--;
            else if (Circle[i][j] * cnt < sum) Circle[i][j]++;
        }
    }
}

void rotate(int x, int d, int k) {
    for (int i = x; i <= N; i += x) {
        deque<int> dq;
        for (int j = 0; j < M; j++) {
            dq.push_back(Circle[i - 1][j]);
        }

        for (int j = 0; j < k; j++) {
            if (d) { // 반시계
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else { // 시계
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }

        for (int j = 0; j < M; j++) {
            Circle[i - 1][j] = dq.front();
            dq.pop_front();
        }
    }
}

int calc() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Circle[i][j] != -1) {
                sum += Circle[i][j];
            }
        }
    }

    return sum;
}

int main() {
    FastIO
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Circle[i][j];
        }
    }

    while (T--) {
        int x, d, k;
        cin >> x >> d >> k;
        
        rotate(x, d, k);
        auto groups = find();        
        if (!groups.empty()) erase(groups);
        else adjust();
    }

    int ans = calc();
    cout << ans << '\n';
    return 0;
}
