#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

char A[5][5];
bool D[5][5];

int ans = 0;
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void input() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> A[i][j];
        }
    }
}

bool check(int last) {
    int all = 0, dasom = 0;
    int x = last / 5, y = last % 5;

    bool V[5][5];
    memset(V, false, sizeof(V));

    queue<pair<int,int>> q;
    q.push({ x, y });
    V[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        
        all++;
        if (A[cx][cy] == 'S') dasom++;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (!D[nx][ny] || V[nx][ny]) continue;
            
            q.push({ nx, ny });
            V[nx][ny] = true;
        }
    }

    return all >= 7 && dasom >= 4;
}

void dfs(int idx, int depth) {
    if (depth == 7) {
        if (check(idx - 1)) ans++;
        return;
    }
    
    for (int i = idx; i < 25; i++) {
        D[i / 5][i % 5] = true;
        dfs(i + 1, depth + 1);
        D[i / 5][i % 5] = false;
    }
}

int main() {
    FastIO
    input();
    dfs(0, 0);
    cout << ans << '\n';
    return 0;
}
