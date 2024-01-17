#include <iostream>
#define INF 1000000
using namespace std;

int N = 0;
int arr[101010] = {0,};
int dance[101010][5][5] = {0,};
int power(int from, int to);
int f(int i, int l, int r);
void print(int i);

// Counter Example
// It was really hard to figure out ...
// 3 4 3 2 3 0

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int x;
    while (true) {
        cin >> x;
        if (x == 0) break;
        arr[++N] = x;
    }

    int cur = arr[1];
    dance[1][cur][0] = dance[1][0][cur] = 2;
    
    for (int i = 2; i <= N; i++) {
        cur = arr[i];
        for (int k = 0; k <= 4; k++) {
            if (k == cur) continue;
            dance[i][cur][k] = f(i, cur, k);
            dance[i][k][cur] = f(i, k, cur);    
        }
    }

    int res = INF;
    for (int k = 0; k <= 4; k++) {
        if (k == cur) continue;
        if (dance[N][cur][k] == 0) continue;
        if (dance[N][cur][k] < res) res = dance[N][cur][k];
    }
    for (int k = 0; k <= 4; k++) {
        if (k == cur) continue;
        if (dance[N][k][cur] == 0) continue;
        if (dance[N][k][cur] < res) res = dance[N][k][cur];
    }
    if (res == INF) res = 0;

    cout << res;    
    return 0;
}

int power(int from, int to) {
    if (from == 0 or to == 0) return 2;
    else if (from == to) return 1;
    else if (abs(from - to) == 2) return 4;
    else return 3;
}

int f(int i, int l, int r) {
    int cur = arr[i];
    int res = INF;

    for (int k = 0; k <= 4; k++) {
        if (r == k or r == cur) continue;
        if (dance[i-1][k][r] == 0) continue;
        int value = dance[i-1][k][r] + power(k, cur);
        if (value < res) res = value;
    }
    for (int k = 0; k <= 4; k++) {
        if (l == k or l == cur) continue;
        if (dance[i-1][l][k] == 0) continue;
        int value = dance[i-1][l][k] + power(k, cur);
        if (value < res) res = value;
    }
    
    if (res == INF) res = 0;

    return res;
}

void print(int i) {
    for (int x = 0; x <= 4; x++) {
        for (int y = 0; y <= 4; y++) {
            cout << dance[i][x][y] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    return;
}
