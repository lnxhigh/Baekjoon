#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 7;
vector<int> graph[MAX];
vector<int> white, blue;
bool visited[MAX];

void dfs(int cur, bool flag) {
    visited[cur] = true;
    vector<int> &v = flag ? white : blue;
    v.push_back(cur);

    for (int next : graph[cur]) {
        if (!visited[next]) dfs(next, !flag);
    }
}

void print(const vector<int> &v) {
    cout << v.size() << '\n';
    for (int k : v) cout << ++k << ' ';
    cout << '\n';
}

int main() {
    FastIO
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        int L; cin >> L;
        while (L--) {
            int X; cin >> X; --X;
            graph[i].push_back(X);
            graph[X].push_back(i);
        }
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) dfs(i, i & 1);
    }
    
    sort(white.begin(), white.end());
    sort(blue.begin(), blue.end());
    
    print(white); 
    print(blue);
    return 0;
}
