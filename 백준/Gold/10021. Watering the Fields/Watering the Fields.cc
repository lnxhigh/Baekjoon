#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using Point = pair<int,int>;
using Edge = pair<int,pair<int,int>>;
const int MAX = 1 << 11;

int N, C;

vector<Point> V;
vector<Edge> E;
int P[MAX];

int find(int x) {
    if (x == P[x]) return x;
    return P[x] = find(P[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    x > y ? P[x] = y : P[y] = x;
    return true;
}

int dist(const Point &A, const Point &B) {
    int dx = A.first - B.first;
    int dy = A.second - B.second;
    return dx * dx + dy * dy;
}

void input() {
    cin >> N >> C;
    
    V.reserve(N);
    E.reserve(N * N);
    iota(P, P + N, 0);

    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        V[i] = { x, y };
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int value = dist(V[i], V[j]);
            if (value < C) continue;

            pair<int,int> p = { i, j };
            E.push_back({ value, p });
        }
    }

    sort(E.begin(), E.end());
}

int MST() {
    int ans = 0, cnt = N;

    for (const auto& [value, p] : E) {
        auto [u, v] = p;
        bool isMerged = merge(u, v);
        
        if (isMerged) {
            ans += value;
            cnt--;
        }
    }

    if (cnt > 1) return -1;
    return ans;
}

int main() {
    FastIO
    input();
    int ans = MST();
    cout << ans << '\n';
    return 0;
}
