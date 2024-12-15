#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int R, C, N;
char A[128][128];

int dx[4] = { +1, 0, 0, -1 };
int dy[4] = { 0, -1, +1, 0 };

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
        }
    }
}

void print(char arr[128][128]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout<< arr[i][j];
        }
        cout<<endl;
    }
}

vector<pair<int,int>> cluster(int x, int y) {
    vector<pair<int,int>> ret;
    queue<pair<int,int>> q;
    if (A[x][y] == '.') return ret;

    pair<int,int> init = { x, y };
    q.push(init);

    bool visited[128][128];
    memset(visited, 0, sizeof(visited));
    visited[x][y] = true;

    while (!q.empty()) {
        pair<int,int> cur = q.front();
        auto [x, y] = cur;
        ret.push_back(cur);
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (visited[nx][ny] || A[nx][ny] == '.') continue;

            pair<int,int> nxt = { nx, ny };
            q.push(nxt);
            visited[nx][ny] = true;
        }
    }

    return ret;
}

int height(const vector<pair<int,int>> &group) {
    bool same[128][128];
    memset(same, 0, sizeof(same));
    for (auto [x, y] : group) {
        same[x][y] = true;
        if (x == R - 1) return 0;
    }

    int ret = 0;
    for (auto [x, y] : group) {
        // (x, y) 에서 얼마나 떨어질 수 있는가
        int h = 0;
        while (true) {
            int nxt = x + h + 1;
            if (nxt >= R) break;
            if (!same[nxt][y] && A[nxt][y] == 'x') break;
            h++;
        }

        if (ret == 0) ret = h;
        else ret = min(ret, h);
    }
    
    return ret;
}

void fall(const vector<pair<int,int>> &group, int h) {
    if (h == 0) return;
    for (auto [x, y] : group) A[x][y] = '.';
    for (auto [x, y] : group) A[x + h][y] = 'x';
}

void destroy(int x, int y) {
    A[x][y] = '.';

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        
        auto v = cluster(nx, ny);
        int h = height(v);
        fall(v, h);
    }
}

pair<int,int> shoot(int h, bool fromLeft) {
    int y = fromLeft ? 0 : C - 1;
    int d = fromLeft ? +1 : -1;
    
    while ((y >= 0 && y < C) && A[h][y] != 'x') y += d;
    return { h, y };
}

void solve() {
    cin >> N;
    bool fromLeft = true;
    for (int i = 0; i < N; i++) {
        int h; cin >> h; h = R - h;
        
        auto [x, y] = shoot(h, fromLeft);
        if (y >= 0 && y < C) destroy(x, y);
        fromLeft ^= true;
    }

    print(A);
}

int main() {
    FastIO
    input();
    solve();
    return 0;
}
