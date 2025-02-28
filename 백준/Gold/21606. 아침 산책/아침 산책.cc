#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 200'001;

int N;
bool A[MAX];
vector<int> tree[MAX];
bool V[MAX];

long long bfs(int x) {
    long long cnt = 0;
    
    queue<int> q;
    q.push(x);
    V[x] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int nxt : tree[x]) {
            if (V[nxt]) continue;

            if (A[nxt]) cnt++;
            else q.push(nxt), V[nxt] = true;
        }
    }

    return cnt * (cnt - 1);
}

int main() {
    FastIO
    cin >> N;

    for (int i = 1; i <= N; i++) {
        char x; cin >> x;
        A[i] = (x == '1');
    }

    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    long long ans = 0;

    for (int i = 1; i <= N; i++) {
        if (A[i]) {
            for (int nxt : tree[i]) {
                if (A[nxt]) ans++;
            }
        }
        else {
            ans += bfs(i);
        }
    }

    cout << ans << '\n';
    return 0;    
}
