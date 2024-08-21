#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int N, M, V;
const int MAX = 1 << 6, INF = 1 << 20;;
const int EMPTY = 0, WALL = 1, VIRUS = 2;

int Lab[MAX][MAX];
vector<pair<int,int>> viruses;
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };
bool visited[MAX][MAX];

int simulate(int choice) {
    memset(visited, 0, sizeof(visited));

    queue<pair<pair<int,int>,int>> q;
    for (int k = 0; k < V; k++) {
        if (choice & (1 << k)) {
            pair<int,int> p = viruses[k];
            int x = p.first, y = p.second;
            q.push({{ x, y }, 0});
            visited[x][y] = true;
        }
    }

    int res = 0;

    while (!q.empty()) {
        pair<int,int> cur = q.front().first;
        int x = cur.first, y = cur.second;
        int depth = q.front().second;
        if (Lab[x][y] == EMPTY) res = max(res, depth);
        
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny] || Lab[nx][ny] == WALL) continue;
            visited[nx][ny] = true;
            
            pair<int,int> next = { nx, ny };
            q.push({ next, depth+1 });
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && Lab[i][j] == EMPTY) res = INF;
        }
    }

    return res;
}

int main() {
    FastIO

    // Input
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Lab[i][j];
            if (Lab[i][j] == VIRUS) {
                viruses.push_back({ i, j });
            }
        }
    }

    // Select viruses to activate
    V = viruses.size();
    vector<int> choices;

    for (int i = 0; i < (1 << V); i++) {
        int cnt = 0;
        for (int k = 0; k < V; k++) {
            if (i & (1 << k)) cnt++;
        }
        if (cnt == M) choices.push_back(i);
    }

    // Simulate
    int res = INF;
    for (int choice : choices) {
        int tmp = simulate(choice);
        res = min(res, tmp);
    }

    // Answer
    if (res >= INF) res = -1;
    cout << res << '\n';
    return 0;
}
