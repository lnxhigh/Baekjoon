#include <bits/stdc++.h>
#define N_MAX 3001
using namespace std;

int Find(int x, int parent[N_MAX]) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x], parent);
}

void Union(int x, int y, int parent[N_MAX]) {
    x = Find(x, parent);
    y = Find(y, parent);
    if (x == y) return;

    if      (x < y) parent[y] = x;
    else if (x > y) parent[x] = y;
    return;
}

int solve() {
    int N;
    cin >> N;

    int x[N_MAX], y[N_MAX], R[N_MAX];
    for (int n = 1; n <= N; n++) {
        cin >> x[n] >> y[n] >> R[n];
    }

    int parent[N_MAX];
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            int r  = R[i] + R[j];
            if (dx*dx + dy*dy <= r*r) {
                Union(i, j, parent);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        Find(i, parent);
    }

    unordered_set<int> s;
    for (int i = 1; i <= N; i++) s.insert(parent[i]);
    int res = s.size();
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        cout << solve() << '\n';
    }
    return 0;
}