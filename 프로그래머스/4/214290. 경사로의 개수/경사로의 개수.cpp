#include <bits/stdc++.h>

using namespace std;
const int MAX = 8;
const int MOD = 1000000007;

int dp[MAX][MAX][MAX][MAX][100];
bool chk[MAX][MAX][MAX][MAX][100];
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int mtrx[MAX * MAX][MAX * MAX];

int dfs(int x, int y, int ex, int ey, int idx,
    const vector<vector<int>> &grid, const vector<int> &arr
) {
    if (idx == arr.size()) return x == ex && y == ey;
    if (chk[x][y][ex][ey][idx]) return dp[x][y][ex][ey][idx];
    
    int r = grid.size();
    int c = grid[0].size();
    
    int sum = 0;
    
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        
        int diff = grid[nx][ny] - grid[x][y];
        if (diff != arr[idx]) continue;
        
        sum += dfs(nx, ny, ex, ey, idx + 1, grid, arr);
        sum %= MOD;
    }
    
    chk[x][y][ex][ey][idx] = true;
    return dp[x][y][ex][ey][idx] = sum;
}

void multiply(int X[MAX * MAX][MAX * MAX], int Y[MAX * MAX][MAX * MAX], 
    int R[MAX * MAX][MAX * MAX], int n
) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long sum = 0;
            for (int k = 0; k < n; k++) {
                sum += (long long) X[i][k] * Y[k][j];
                sum %= MOD;
            }
            R[i][j] = sum;
        }
    }
}

int power(int mtrx[MAX * MAX][MAX * MAX], int n, int k) {
    int res[MAX * MAX][MAX * MAX] = { 0 };
    int mul[MAX * MAX][MAX * MAX] = { 0 };
    
    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
        for (int j = 0; j < n; j++) {
            mul[i][j] = mtrx[i][j];
        }
    }
    
    while (k) {
        if (k & 1) {
            int tmp[MAX * MAX][MAX * MAX] = { 0 };
            multiply(res, mul, tmp, n);
            memcpy(res, tmp, sizeof(tmp));
        }
        
        int tmp[MAX * MAX][MAX * MAX] = { 0 };
        multiply(mul, mul, tmp, n);
        memcpy(mul, tmp, sizeof(tmp));
        
        k >>= 1;
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += res[i][j];
            sum %= MOD;
        }
    }
    
    return sum;
}

int solution(vector<vector<int>> grid, vector<int> arr, int k) {
    int r = grid.size();
    int c = grid[0].size();

    // Transition matrix (k = 1)
    
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    int cur = x * c + y, nxt = i * c + j;
                    mtrx[cur][nxt] = dfs(x, y, i, j, 0, grid, arr);
                }
            }
        }
    }
    
    // Power of matrix
    
    int ans = power(mtrx, r * c, k);
    return ans;
}
