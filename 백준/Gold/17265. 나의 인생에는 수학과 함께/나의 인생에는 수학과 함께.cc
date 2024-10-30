#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 20;
char Map[5][5];

int f(int x, int y, char op) {
    if (op == '+') return x + y;
    else if (op == '-') return x - y;
    else if (op == '*') return x * y;
    return 0;
}

int dfs(int x, int y, bool flag) {
    if (x < 0 || y < 0) return flag ? -INF : INF;
    int k = Map[x][y] - '0';
    if (x == 0 && y == 0) return k;

    int first  = dfs(x - 1, y, flag);
    int second = dfs(x, y - 1, flag);
    
    if (isdigit(Map[x][y])) {
        first  = f(first , k, Map[x - 1][y]);
        second = f(second, k, Map[x][y - 1]);
    }

    if (x == 0) return second;
    if (y == 0) return first;

    return flag ? max(first, second) : min(first, second);;
}

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Map[i][j];
        }
    }

    cout << dfs(N - 1, N - 1, true)  << ' ';
    cout << dfs(N - 1, N - 1, false) << '\n';
    return 0;
}
