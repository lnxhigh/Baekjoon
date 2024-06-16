#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 25;
bool Map[MAX][MAX];
bool visited[MAX][MAX];
vector<int> cnt;

int dx[4] = { -1, +1, 0, 0 };
int dy[4] = { 0, 0, -1, +1 };

void dfs(int x, int y, int &depth) {
    visited[x][y] = true;
    depth++;

    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) continue;
        if (visited[nextX][nextY]) continue;
        if (!Map[nextX][nextY]) continue;
        
        dfs(nextX, nextY, depth);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            Map[i][j] = (c == '1');
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!Map[i][j]) continue;
            if (visited[i][j]) continue;

            int depth = 0;
            dfs(i, j, depth);
            cnt.push_back(depth);
        }
    }

    cout << cnt.size() << '\n';
    sort(cnt.begin(), cnt.end());
    for (int k : cnt) { cout << k << '\n'; }

    return 0;
}
