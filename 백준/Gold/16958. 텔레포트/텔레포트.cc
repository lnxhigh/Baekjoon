#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int N, T, M;
const int MAX = 1 << 10;
const int INF = 1 << 20;

pair<int,int> locs[MAX];
bool isSpecial[MAX];
vector<int> specials;

int dist(int A, int B) {
    int dx = locs[A].first - locs[B].first;
    int dy = locs[A].second - locs[B].second;
    return abs(dx) + abs(dy);
}

int closest(int X) {
    int res = -1;
    int minDist = INF;

    for (int k : specials) {
        int d = dist(X, k);
        if (minDist > d) { minDist = d; res = k; } 
    }
    return res;
}

int solve(int A, int B) {
    int D = dist(A, B);
    int X = closest(A), Y = closest(B);
    if (X == Y) return D;
    
    // Manhattan distance satisfies triangle inequality 
    // Do not consider T > dist(X, Y) 
    int V = dist(A, X) + T + dist(B, Y);
    return min(D, V);
}

int main() {
    FastIO
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        int s, x, y;
        cin >> s >> x >> y;
        locs[i] = { x, y };
        isSpecial[i] = s;
        if (s) specials.push_back(i);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        cout << solve(--A, --B) << '\n';
    }
    return 0;
}
