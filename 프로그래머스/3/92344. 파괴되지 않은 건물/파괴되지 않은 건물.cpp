#include <bits/stdc++.h>

using namespace std;
const int MAX = 1 << 10;

int up[MAX][MAX];
int down[MAX][MAX];

int solution(vector<vector<int>> board, vector<vector<int>> skills) {
    int cnt = 0;
    int m = board.size();
    int n = board[0].size();
    
    for (const vector<int> &skill : skills) {
        int type = skill[0];
        int r1 = skill[1], c1 = skill[2];
        int r2 = skill[3], c2 = skill[4];
        int degree = skill[5];
        
        r1++, c1++, r2++, c2++;
        
        if (type == 1) {
            down[r2][c2] += degree;
            up[r1 - 1][c2] += degree;
            up[r2][c1 - 1] += degree;
            down[r1 - 1][c1 - 1] += degree;
        } else if (type == 2) {
            up[r2][c2] += degree;
            down[r1 - 1][c2] += degree;
            down[r2][c1 - 1] += degree;
            up[r1 - 1][c1 - 1] += degree;
        }
    }
    
    for (int x = 1; x <= m; x++) {
        for (int y = 1; y <= n; y++) {
            up[x][y] += up[x - 1][y] + up[x][y - 1] - up[x - 1][y - 1];
            down[x][y] += down[x - 1][y] + down[x][y - 1] - down[x - 1][y - 1];
        }
    }
    
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            int effect = 0;
            effect += up[m][n] - up[x][n] - up[m][y] + up[x][y];
            effect -= down[m][n] - down[x][n] - down[m][y] + down[x][y];
            if (board[x][y] + effect > 0) cnt++;
        }
    }    
    
    return cnt;
}
