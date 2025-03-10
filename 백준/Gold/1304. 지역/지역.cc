#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 3001;

int V, E;
vector<int> graph[MAX];

bool check(int num) {
    if (V % num != 0) return false;
    int cnt = V / num;

    for (int i = 0; i < V; i++) {
        for (int nxt : graph[i]) {
            if (i / cnt != nxt / cnt) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    FastIO
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int x, y; cin >> x >> y; --x, --y;
        if (x > y) graph[x].push_back(y);
    }
    
    int ans = 1;
    for (int i = 1; i <= V; i++) {
        if (check(i)) ans = i;
    }

    cout << ans << '\n';
    return 0;
}
