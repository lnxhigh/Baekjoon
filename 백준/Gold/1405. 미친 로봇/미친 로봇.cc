#include <bits/stdc++.h>
using namespace std;

int N;
int P[4];
double P_[4];

const int MAX = 1 << 5;

int state[4];
bool visited[MAX][MAX];

int startX = 1 << 4, startY = 1 << 4;
int dx[4] = { 0, 0, +1, -1 };
int dy[4] = { +1, -1, 0, 0 };

double ans = 0.0;

void move(int curX, int curY, int depth) {
    if (depth == N) {
        double res = 1.0;
        for (int i = 0; i < 4; i++) {
            for (int n = 0; n < state[i]; n++) res *= P_[i];
        }
        ans += res;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nextX = curX + dx[i];
        int nextY = curY + dy[i];
        if (visited[nextX][nextY]) continue;

        state[i]++;
        visited[nextX][nextY] = true;
        move(nextX, nextY, depth + 1);
        
        state[i]--;
        visited[nextX][nextY] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < 4; i++) cin >> P[i];
    for (int i = 0; i < 4; i++) P_[i] = P[i] / 100.0;

    visited[startX][startY] = true;
    move(startX, startY, 0);

    cout << setprecision(16);
    cout << ans << "\n";
    return 0;
}
