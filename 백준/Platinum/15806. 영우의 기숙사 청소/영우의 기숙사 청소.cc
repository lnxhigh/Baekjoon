#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 305;

int N, M, K, T;

// 최초로 곰팡이가 발생하는 시점을 저장
int D[MAX][MAX];

int dx[8] = { -1, -2, -2, -1, +1, +2, +2, +1 };
int dy[8] = { +2, +1, -1, -2, -2, -1, +1, +2 };

// T = t 일 때 (x, y) 에 곰팡이가 존재하는지 검사
bool dirty(int x, int y, int t) {
    if (D[x][y] == -1 || D[x][y] > t) return false;
    else if (D[x][y] == t) return true;

    bool odd = false, even = false;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

        odd  |= (D[nx][ny] == D[x][y]);
        even |= true;
    }
    
    int diff = t - D[x][y];
    return diff & 1 ? odd : even;
}

int main() {
    FastIO
    cin >> N >> M >> K >> T;
    
    queue<tuple<int,int,int>> q;
    memset(D, -1, sizeof(D));

    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        q.push({ x, y, 0 });
        D[x][y] = 0;
    }

    while (!q.empty()) {
        auto [x, y, day] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (D[nx][ny] != -1) continue;

            q.push({ nx, ny, day + 1 });
            D[nx][ny] = day + 1;
        }
    }

    bool flag = false;
    for (int i = 0; i < K; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        flag |= dirty(x, y, T);
    }
    
    string ans = flag ? "YES" : "NO";
    cout << ans << '\n';
    return 0;
}
