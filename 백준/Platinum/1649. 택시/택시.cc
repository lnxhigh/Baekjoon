#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int N, M;
vector<int> graph[MAX];
int X, Y;

int K;
set<int> C;

int inDegree[MAX];
long long D[MAX];

void input() {
    cin >> N >> M;
    while (M--) {
        int A, B; cin >> A >> B;
        graph[A].push_back(B);
        inDegree[B]++;
    }
    cin >> X >> Y;

    cin >> K;
    for (int i = 0; i < K; i++) {
        int V; cin >> V;
        C.insert(V);
    }
}

long long solve() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    D[X] = 1;

    for (int i = 1; i <= N; i++) {
        int cur = q.front();
        q.pop();

        if (C.count(cur)) {
            for (int k = 1; k <= N; k++) {
                if (k != cur) D[k] = 0;
            }
        }

        for (int nxt : graph[cur]) {
            D[nxt] += D[cur];
            if (--inDegree[nxt] == 0) q.push(nxt);
        }
    }

    return D[Y];
}

int main() {
    FastIO
    input();
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
