#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

bool train[4][5][3] = {
    { 
        1, 1, 1, 
        0, 0, 1, 
        1, 1, 1,
        1, 0, 0,
        1, 1, 1
    },

    {
        1, 1, 1,
        1, 0, 0,
        1, 1, 1,
        0, 0, 1,
        1, 1, 1
    },

    {
        1, 1, 1,
        1, 0, 0,
        1, 0, 0,
        1, 0, 0,
        1, 1, 1
    },

    {
        1, 1, 1,
        0, 0, 1,
        0, 0, 1,
        0, 0, 1,
        1, 1, 1
    }
};

int n;
string str;

bool arr[5][200000 * 3];
bool vis[5][200000 * 3];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void dfs(int x, int y) {
    vis[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= (3 * n)) continue;
        else if (arr[nx][ny] || vis[nx][ny]) continue;

        dfs(nx, ny);
    }
}

int main() {
    FastIO
    
    cin >> n;
    cin >> str;

    for (int t = 0; t < n; t++) {
        char x = str[t];

        int idx = 0;
        if (x == '2') idx = 0;
        else if (x == '5') idx = 1;
        else if (x == '[') idx = 2;
        else if (x == ']') idx = 3;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 3; j++) {
                arr[i][3 * t + j] = train[idx][i][j];
            }
        }
    }
    
    int ans = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < (3 * n); j++) {
            if (arr[i][j] || vis[i][j]) continue;

            ans++;
            dfs(i, j);
        }
    }

    cout << ans << '\n';

    return 0;
}
