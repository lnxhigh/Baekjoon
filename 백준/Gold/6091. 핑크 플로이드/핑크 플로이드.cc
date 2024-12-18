#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int N;
vector<tuple<int,int,int>> Edges;

int Parent[MAX];
bool Tree[MAX][MAX];

int find(int x) {
    if (x == Parent[x]) return x;
    return Parent[x] = find(Parent[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    x > y ? Parent[x] = y : Parent[y] = x;
    return true;
}

void input() {
    cin >> N;
    Edges.reserve(N * N / 2);
    iota(Parent, Parent + N, 0);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int dist; cin >> dist;
            Edges.push_back({ dist, i, j });
        }
    }
    sort(Edges.begin(), Edges.end());
}

void MST() {
    for (const auto& [dist, u, v] : Edges) {
        bool isMerged = merge(u, v);
        if (isMerged) Tree[u][v] = Tree[v][u] = true;
    }
}

void print(int i) {
    int cnt = 0;
    
    for (int j = 0; j < N; j++) {
        if (Tree[i][j]) cnt++;
    }
    cout << cnt << ' ';
    
    for (int j = 0; j < N; j++) {
        if (Tree[i][j]) cout << j + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    FastIO
    input();

    // Claim: MST is a reconstruction
    MST();
    
    for (int i = 0; i < N; i++) {
        print(i);
    }

    return 0;
}
