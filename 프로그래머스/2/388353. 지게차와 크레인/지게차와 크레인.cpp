#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    int R = storage.size();
    int C = storage[0].size();
    
    vector<pair<int,int>> init;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (i == 0 || i == R - 1 || j == 0 || j == C - 1) {
                init.push_back({ i, j });
            }
        }
    }
    
    for (string request : requests) {
        char req = request[0];
        
        if (request.size() == 1u) {
            queue<pair<int,int>> q;
            vector<vector<bool>> vis(R, vector<bool>(C));
            vector<pair<int,int>> update;
            
            for (auto [x, y] : init) {
                q.push({ x, y });
                vis[x][y] = true;
            }
            
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                
                if (storage[x][y] != '.') {
                    if (storage[x][y] == req) {
                        update.push_back({ x, y });
                    }
                    continue;
                }
                
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                    else if (vis[nx][ny]) continue;
                    
                    q.push({ nx, ny });
                    vis[nx][ny] = true;
                }
            }
            
            answer += update.size();
            for (auto [x, y] : update) {
                storage[x][y] = '.';
            }
        }
        else if (request.size() == 2u) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (storage[i][j] == req) {
                        cout << req << ' ' << i << ' ' << j << '\n';
                        
                        answer++;
                        storage[i][j] = '.';
                    }
                }
            }
        }
    }
        
    return R * C - answer;
}
