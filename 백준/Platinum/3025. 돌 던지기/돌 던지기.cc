#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAXR = 1 << 15;
const int MAXC = 1 << 5;

int R, C, T;
string Map[MAXR];
stack<pair<int,int>> st[MAXC];

int main() {
    FastIO

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> Map[i];
    }
    Map[R] = string(C, 'X');

    for (int i = 0; i < C; i++) {
        int x = 0;
        while (Map[x][i] != 'X') {
            st[i].push({ x++, i });
        }
    }

    cin >> T;
    while (T--) {
        int idx; cin >> idx; --idx;

        while (!st[idx].empty()) {
            auto [x, y] = st[idx].top();
            if (Map[x][y] == 'O') st[idx].pop();
            else break;
        }
        
        assert(!st[idx].empty());
        auto [x, y] = st[idx].top();
        bool stopped = false;

        while (!stopped) {
            if (Map[x + 1][y] == 'X') {
                stopped = true;
            }
            else if (Map[x + 1][y] == '.') {
                x++;
            }
            else if (Map[x + 1][y] == 'O') {
                if (y > 0 && Map[x][y - 1] == '.' && Map[x + 1][y - 1] == '.') x++, y--;
                else if (y < C - 1 && Map[x][y + 1] == '.' && Map[x + 1][y + 1] == '.') x++, y++;
                else stopped = true;
            }

            if (!stopped) st[idx].push({ x, y });
        }
        
        Map[x][y] = 'O';
    }

    for (int i = 0; i < R; i++) {
        cout << Map[i] << '\n';
    }
    
    return 0;
}
