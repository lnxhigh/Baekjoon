#include <bits/stdc++.h>

using namespace std;
using XY = pair<int,int>;

const int MAX = 64;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

bool vis_board[MAX][MAX];
bool vis_table[MAX][MAX];

vector<XY> bfs(int x, int y, int n, 
    const vector<vector<int>> &arr, bool vis[MAX][MAX]
) {
    queue<XY> q;
    vector<XY> result;
    
    q.push({ x, y });
    vis[x][y] = true;
    
    int minX = n, minY = n;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        minX = min(minX, x);
        minY = min(minY, y);
        result.push_back({ x, y });
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || arr[nx][ny] == 1) continue;
            
            q.push({ nx, ny });
            vis[nx][ny] = true;
        }
    }
    
    for (auto &p : result) {
        p.first -= minX;
        p.second -= minY;
    }
    
    return result;
}

void rotate(int arr[6][6]) {
    int tmp[6][6];
    int minX = 6, minY = 6;
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            tmp[i][j] = arr[j][5 - i];
        }
    }
    
    vector<XY> vec;
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (!tmp[i][j]) continue;
            
            minX = min(minX, i);
            minY = min(minY, j);
            vec.push_back({ i, j });
        }
    }
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            arr[i][j] = 0;
        }
    }
    
    for (auto [x, y] : vec) arr[x - minX][y - minY] = 1;
}

bool compare(const vector<XY> &vec, const vector<XY> &target) {
    int arr[6][6] = { 0 };
    for (auto [x, y] : vec) {
        arr[x][y] = 1;
    }
    
    int t[6][6] = { 0 };
    for (auto [x, y] : target) {
        t[x][y] = 1;
    }
    
    for (int cnt = 0; cnt < 4; cnt++) {
        rotate(t);
        
        bool chk = true;
        
        for (int x = 0; x < 6 && chk; x++) {
            for (int y = 0; y < 6 && chk; y++) {
                if (arr[x][y] != t[x][y]) {
                    chk = false;
                }
            }
        }
        
        if (chk) return true;
    }
    
    
    
    return false;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> game_table) {
    vector<vector<XY>> board_pieces;
    vector<vector<XY>> table_pieces;
    
    int n = game_board.size();
    
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            game_table[x][y] = 1 - game_table[x][y];
        }
    }
    
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (!game_board[x][y] && !vis_board[x][y]) {
                auto vec = bfs(x, y, n, game_board, vis_board);
                board_pieces.push_back(vec);
            }
            if (!game_table[x][y] && !vis_table[x][y]) {
                auto vec = bfs(x, y, n, game_table, vis_table);
                table_pieces.push_back(vec);
            }
        }
    }
    
    int ans = 0;
    vector<bool> used(table_pieces.size());
    
    for (auto &piece : board_pieces) {
        for (int i = 0; i < table_pieces.size(); i++) {
            auto &target = table_pieces[i];
            bool chk = !used[i] && compare(piece, target);
            if (!chk) continue;
            
            ans += target.size();
            used[i] = true;
            break;
        }
    }
    
    for (auto &piece : board_pieces) {
        int arr[6][6] = {0};
        for (auto [x,y] : piece) {
            arr[x][y] = 1;
        }
        rotate(arr);
        for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
        cout << arr[i][j] << ' ';
        }
        cout<<endl;
        }
        cout<<endl;
    }
    
    return ans;
}
