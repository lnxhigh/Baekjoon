#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

// 약간 느림

int n;
int arr[10][4][4][4];
char element[10][4][4][4];

int table[256];
int quality[5] = { 7, 5, 3, 2, 0 };

void input() {
    cin >> n;

    string str = "RBGYW";
    for (int i = 0; i < 5; i++) {
        table[str[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                cin >> arr[i][0][x][y];
            }
        }

        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                cin >> element[i][0][x][y];
            }
        }

        for (int k = 1; k < 4; k++) {
            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 4; y++) {
                    arr[i][k][x][y] = arr[i][k - 1][y][3 - x];
                    element[i][k][x][y] = element[i][k - 1][y][3 - x];
                }
            }
        }
    }
}

void update(int dat[4][4], int x, int y, int nums[5][5]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int sum = nums[i + x][j + y] + dat[i][j];
            sum = max(sum, 0);
            sum = min(sum, 9);
            nums[i + x][j + y] = sum;
        }
    }
}

void update(char dat[4][4], int x, int y, char color[5][5]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (dat[i][j] != 'W') {
                color[x + i][y + j] = dat[i][j];
            }
        }
    }
}

int f(int order[3]) {
    int ret = 0;
    int t = 1 << 12;

    for (int i = 0; i < t; i++) {
        // Init

        int nums[5][5] = {0};
        char color[5][5];

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                color[i][j] = 'W';
            }
        }

        // Simulate

        for (int k = 0; k < 3; k++) {
            int shift = k << 1;
            int mask = 0b11 << shift;
            int xy = (i & mask) >> shift;
            int x = xy / 2, y = xy % 2;

            shift += 6, mask <<= 6;
            int dir = (i & mask) >> shift;

            update(arr[order[k]][dir], x, y, nums);
            update(element[order[k]][dir], x, y, color);
        }

        int res[5] = {0};

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                res[table[color[i][j]]] += nums[i][j];
            }
        }

        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += res[i] * quality[i];
        }
        ret = max(ret, sum);
    }

    return ret;
}

int solve() {
    int ret = 0;

    for (int i = 0; i < (1 << n); i++) {
        int cnt = __builtin_popcount(i);
        if (cnt != 3) continue;

        int idx = 0;
        int x = 0, y = 0, z = 0;
        while ((i >> idx & 1) == 0) idx++; x = idx++;
        while ((i >> idx & 1) == 0) idx++; y = idx++;
        while ((i >> idx & 1) == 0) idx++; z = idx++;

        int order[6][3] = {
            { x, y, z }, { x, z, y }, 
            { y, x, z }, { y, z, x }, 
            { z, x, y }, { z, y, x }
        };

        for (int t = 0; t < 6; t++) {
            ret = max(ret, f(order[t]));
        }
    }

    return ret;
}

int main() {
    FastIO
    input();
    int ans = solve();
    cout << ans << '\n';

    return 0;
}
