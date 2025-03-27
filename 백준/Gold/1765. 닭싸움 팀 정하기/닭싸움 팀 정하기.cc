#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int N, M;
vector<int> friends[MAX];
vector<int> enemies[MAX];
bool visited[MAX];

void match(int cur, bool flag, vector<int> &one, vector<int> &other) {
    visited[cur] = true;
    vector<int> &vec = flag ? one : other;
    vec.push_back(cur);

    for (int nxt : enemies[cur]) {
        if (!visited[nxt]) match(nxt, !flag, one, other);
    }
}

void regroup(int cur) {
    visited[cur] = true;
    for (int nxt : friends[cur]) {
        if (!visited[nxt]) regroup(nxt);
    }
}

int main() {
    FastIO
    cin >> N >> M;

    while (M--) {
        char c; cin >> c;
        int x, y; cin >> x >> y; --x, --y;    
        
        vector<int>* graph = (c == 'F') ? friends : enemies;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;

        vector<vector<int>> groups(2);
        match(i, true, groups[0], groups[1]);

        for (auto& group : groups) {
            for (size_t i = 0; i < group.size(); i++) {
                for (size_t j = i + 1; j < group.size(); j++) {
                    int x = group[i], y = group[j];
                    friends[x].push_back(y);
                    friends[y].push_back(x);
                }
            }
        }
    }

    int ans = 0;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        regroup(i);
        ans++;
    }

    cout << ans << '\n';
    return 0;
}
