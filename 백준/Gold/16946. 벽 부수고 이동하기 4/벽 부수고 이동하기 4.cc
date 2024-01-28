#include <iostream>
#include <utility>
#include <queue>
#include <set>
#define R_MAX 1001
#define C_MAX 1001
#define X first
#define Y second
using namespace std;

int R, C;
int map[R_MAX][C_MAX];
int depth_map[R_MAX][C_MAX] = {0,};
int without_wall[R_MAX][C_MAX] = {0,};
int visited[R_MAX][C_MAX] = {0,};
int parent[R_MAX*C_MAX];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

pair<int,int> find(pair<int, int> loc) {
    int x = loc.X * C + loc.Y;
    int root = find(x);
    return { root / C, root % C };
}

void merge(pair<int,int> left, pair<int,int> right) {
    int x = left.X * C + left.Y;
    int y = right.X * C + right.Y;

    x = find(x); y = find(y);
    if (x == y) return;
    
    if (x > y) parent[x] = y;
    else parent[y] = x;
    return;
}

void bfs(int r, int c, int map[R_MAX][C_MAX], int depth_map[R_MAX][C_MAX]) {
    int dr[4] = {0, 0, +1, -1};
    int dc[4] = {-1, +1, 0, 0};
    queue<pair<int,int>> q;
    vector<pair<int,int>> coord;
    int res = 0;
    pair<int,int> start = {r,c};

    q.push(start);
    visited[start.X][start.Y]++;
    coord.push_back(start);
    res++;

    while (not q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int,int> next = {cur.X + dr[i], cur.Y + dc[i]};
            if (next.X < 0 || next.X >= R) continue;
            if (next.Y < 0 || next.Y >= C) continue;
            if (visited[next.X][next.Y]) continue;

            visited[next.X][next.Y]++;
            if (map[next.X][next.Y]) continue;
            
            q.push(next);
            coord.push_back(next);
            res++;
            merge(cur, next);
        }
    }

    for (pair<int,int> loc : coord) {
        depth_map[loc.X][loc.Y] = res;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    // Input
    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        char line[C_MAX];
        cin >> line;
        for (int c = 0; c < C; c++) {
            map[r][c] = line[c] - '0';
        }
    }

    // Initialize
    for (int i = 0; i < R_MAX*C_MAX; i++) {
        parent[i] = i;
    }
    
    // Construct depth map
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (visited[r][c]) continue;
            if (map[r][c] == 1) continue;
            bfs(r, c, map, depth_map);
        }
    }

    // Consturct the depth map without the wall
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (map[r][c] == 0) continue;

            int depth = 0;
            pair<int,int> cur = {r,c};
            set<pair<int,int>> s;
            int dr[4] = {0, 0, +1, -1};
            int dc[4] = {-1, +1, 0, 0};

            // Use union-find to detect if two points belong to the same group
            for (int i = 0; i < 4; i++) {
                pair<int,int> next = {cur.X + dr[i], cur.Y + dc[i]};
                if (next.X < 0 || next.X >= R) continue;
                if (next.Y < 0 || next.Y >= C) continue;
                if (map[next.X][next.Y] == 1) continue;
                
                s.insert(find(next));
            }
            for (auto iter = s.begin(); iter != s.end(); ++iter) {
                depth += depth_map[iter->X][iter->Y];
            }

            without_wall[cur.X][cur.Y] = ++depth;           
        }
    }
    
    // Print
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cout << without_wall[r][c] % 10;
        }
        cout << '\n';
    }
    
    return 0;
}