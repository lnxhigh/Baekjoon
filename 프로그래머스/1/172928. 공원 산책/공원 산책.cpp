#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

pair<int,int> parse(const string &route) {
    char op = route[0];
    int len = stoi(route.substr(2));
    int dir = 0;
    
    if (op == 'N') dir = 0;
    else if (op == 'S') dir = 2;
    else if (op == 'W') dir = 1;
    else if (op == 'E') dir = 3;
    
    return { dir, len };
}

vector<int> solution(vector<string> arr, vector<string> routes) {
    int x = 0, y = 0;
    int h = arr.size();
    int w = arr[0].size();
    
    // Init
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (arr[i][j] == 'S') {
                x = i, y = j;
            }
        }
    }

    // Move

    for (const string &route : routes) {
        auto [dir, len] = parse(route);
        
        int nx = x + len * dx[dir];
        int ny = y + len * dy[dir];
        bool chk = true;
        
        if (nx < 0 or nx >= h or ny < 0 or ny >= w) continue;
        
        if (x == nx) {
            for (int i = min(y, ny); i <= max(y, ny); i++) {
                chk &= (arr[x][i] != 'X');
            }
        } else if (y == ny) {
            for (int i = min(x, nx); i <= max(x, nx); i++) {
                chk &= (arr[i][y] != 'X');
            }
        }
        
        if (!chk) continue;
        
        x = nx, y = ny;
    }

    return { x, y };
}
