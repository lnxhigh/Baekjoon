#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 20;

int n;
int arr[MAX][MAX];
int ans = 0;

void Up() {
    for (int col = 0; col < n; col++) {
        int now = 0;

        for (int i = 0; i < n; i++) {
            if (!arr[i][col]) continue;
            
            int x = arr[i][col];
            arr[i][col] = 0;

            if (arr[now][col] == 0) arr[now][col] = x;
            else if (arr[now][col] == x) arr[now++][col] = (x << 1);
            else arr[++now][col] = x;
        }
    }
}

void Down() {
    for (int col = 0; col < n; col++) {
        int now = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (!arr[i][col]) continue;
            
            int x = arr[i][col];
            arr[i][col] = 0;

            if (arr[now][col] == 0) arr[now][col] = x;
            else if (arr[now][col] == x) arr[now--][col] = (x << 1);
            else arr[--now][col] = x;
        }
    }
}

void Left() {
    for (int row = 0; row < n; row++) {
        int now = 0;

        for (int i = 0; i < n; i++) {
            if (!arr[row][i]) continue;
            
            int x = arr[row][i];
            arr[row][i] = 0;

            if (arr[row][now] == 0) arr[row][now] = x;
            else if (arr[row][now] == x) arr[row][now++] = (x << 1);
            else arr[row][++now] = x;
        }
    }
}

void Right() {
    for (int row = 0; row < n; row++) {
        int now = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (!arr[row][i]) continue;
            
            int x = arr[row][i];
            arr[row][i] = 0;

            if (arr[row][now] == 0) arr[row][now] = x;
            else if (arr[row][now] == x) arr[row][now--] = (x << 1);
            else arr[row][--now] = x;
        }
    }
}

void MoveTo(int dir) {
    if (dir == 0) Up();
    else if (dir == 1) Down();
    else if (dir == 2) Left();
    else if (dir == 3) Right();
}

bool CheckUpdate(int newArr[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (newArr[i][j] != arr[i][j]) {
                return true;
            }
        }
    }

    return false;
}

int GetMax() {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret = max(ret, arr[i][j]);
        }
    }
    
    return ret;
}

void Search(int x, int rem, bool flag) {
    ans = max(ans, x);
    if (rem == 0 || !flag || (x << rem) <= ans) return;

    int now[MAX][MAX];
    memcpy(now, arr, sizeof(now));

    for (int i = 0; i < 4; i++) {
        MoveTo(i);
        Search(GetMax(), rem - 1, CheckUpdate(now));
        memcpy(arr, now, sizeof(arr));
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    Search(GetMax(), 10, true);
    cout << ans << '\n';
    return 0;
}
