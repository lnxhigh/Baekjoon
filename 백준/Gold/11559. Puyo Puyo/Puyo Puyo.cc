#include <bits/stdc++.h>
using namespace std;

char Field[12][6];
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

vector<pair<int,int>> bfs(int x, int y, bool visited[12][6]) {
    vector<pair<int,int>> group;

    queue<pair<int,int>> q;
    visited[x][y] = true;
    pair<int,int> init = { x, y };
    q.push(init);

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        group.push_back(q.front());
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if (visited[nx][ny] || Field[cx][cy] != Field[nx][ny]) continue;
            
            visited[nx][ny] = true;
            pair<int,int> next = { nx, ny };
            q.push(next);
        }
    }

    return group;
}

vector<vector<pair<int,int>>> find() {
    vector<vector<pair<int,int>>> groups;
    bool visited[12][6];
    memset(visited, 0, sizeof(visited));

    for (int x = 0; x < 12; x++) {
        for (int y = 0; y < 6; y++) {
            if (Field[x][y] == '.' || visited[x][y]) continue;
            auto group = bfs(x, y, visited);
            groups.push_back(group);
        }
    }

    vector<vector<pair<int,int>>> ret;
    for (auto &group : groups) {
        if (group.size() >= 4) {
            ret.push_back(group);
        }
    }

    return ret;
}

void pop(const vector<vector<pair<int,int>>> &groups) {
    for (auto &group : groups) {
        for (auto [x, y] : group) {
            Field[x][y] = '.';
        }
    }
}

pair<int,int> fall(int x, int y) {
    int cur = x;
    while (true) {
        int next = cur + 1;
        if (next >= 12 || Field[next][y] != '.') break;
        cur = next;
    }
    return { cur, y };
}

void arrange() {
    for (int col = 0; col < 6; col++) {
        for (int row = 12 - 1; row >= 0; row--) {
            auto [nx, ny] = fall(row, col);
            if (nx != row) {
                Field[nx][ny] = Field[row][col];
                Field[row][col] = '.';
            }
        }
    }
}

int main() {
    for (int r = 0; r < 12; r++) {
        for (int c = 0; c < 6; c++) {
            cin >> Field[r][c];
        }
    }

    int cnt = 0;
    while (true) {
        auto groups = find();
        if (groups.empty()) break;
        
        ++cnt;
        pop(groups);
        arrange();
    }
    
    cout << cnt << '\n';
    return 0;
}
