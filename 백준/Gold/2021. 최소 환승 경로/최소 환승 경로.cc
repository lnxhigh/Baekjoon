#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100'005;

int n, l;
int src, dst;
vector<int> lines[MAX];
vector<int> stations[MAX];
bool visLine[MAX], visStation[MAX];

int bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({ x, 0 });
    visStation[x] = true;
    if (x == y) return 0;

    while (!q.empty()) {
        auto [cur, cnt] = q.front();
        q.pop();
        if (cur == y) return --cnt;

        for (int line : lines[cur]) {
            if (visLine[line]) continue;
            visLine[line] = true;
            
            for (int nxt : stations[line]) {
                if (visStation[nxt]) continue;
                q.push({ nxt, cnt + 1 });
                visStation[nxt] = true;
            }
        }
    }

    return -1;
}

int main() {
    FastIO

    cin >> n >> l;
    for (int line = 1, station = 0; line <= l; line++) {
        while (cin >> station, station > 0) {
            stations[line].emplace_back(station);
            lines[station].emplace_back(line);
        }
    }
    cin >> src >> dst;

    int ans = bfs(src, dst);
    cout << ans << '\n';

    return 0;
}
