#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 6;

int Row, Col;
int G, R;
int A[MAX][MAX];

enum Color { BLACK, GREEN, RED, PURPLE };
vector<pair<int,int>> S;

int T[MAX][MAX];
Color D[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int bfs(const vector<Color> &P) {
    int flowers = 0;
    queue<tuple<int,int,Color>> q;
    memset(T, 0, sizeof(T));
    memset(D, 0, sizeof(D));

    for (int i = 0; i < (int) S.size(); i++) {
        Color color = P[i];
        if (color == Color::BLACK) continue;  

        auto [x, y] = S[i];
        q.push({ x, y, color });
        T[x][y] = 1;
        D[x][y] = color;
    }

    while (!q.empty()) {
        auto [x, y, color] = q.front();
        q.pop();
        if (D[x][y] == Color::PURPLE) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= Row || ny < 0 || ny >= Col) continue;
            else if (A[nx][ny] == 0 || D[nx][ny] == Color::PURPLE) continue;

            if (T[nx][ny]) {
                if (T[nx][ny] == T[x][y] + 1 && D[nx][ny] != D[x][y]) {
                    flowers++;
                    D[nx][ny] = Color::PURPLE;
                }
            }
            else {
                q.push({ nx, ny, color });
                T[nx][ny] = T[x][y] + 1;
                D[nx][ny] = color;
            }
        }
    }

    return flowers;
}

int main() {
    FastIO
    cin >> Row >> Col;
    cin >> G >> R;
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Col; j++) {
            cin >> A[i][j];
            if (A[i][j] == 2) S.push_back({ i, j });
        }
    }

    vector<Color> P(S.size());
    int B = (int) S.size() - (G + R);
    for (int i = 0; i < (int) S.size(); i++) {
        Color color = (i < B) ? BLACK : (i < B + G) ? GREEN : RED;
        P[i] = color;
    }

    int ans = 0;
    do { ans = max(ans, bfs(P)); } while(next_permutation(P.begin(), P.end()));
    cout << ans << '\n';
    return 0;
}
