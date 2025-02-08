#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 51;

int N;
bool adj[MAX][MAX];
vector<int> graph[MAX];
int inDegree[MAX];

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char x; cin >> x;
            adj[i][j] = (x == 'Y');
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adj[i][j] && !adj[j][i]) {
                graph[i].push_back(j);
                inDegree[j]++;
            }
        }
    }
}

bool solve() {
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    for (int i = 0; i < N; i++) {
        if (q.empty()) return true;
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur]) {
            if (--inDegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    
    return false;
}

int main() {
    FastIO
    input();
    bool cyc = solve();
    string ans = cyc ? "NO" : "YES";
    cout << ans << '\n';
    return 0;
}
