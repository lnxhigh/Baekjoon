#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(false);
#define X first
#define Y second
using namespace std;
using Point = pair<int,int>;

int N;
const int MAX = 1 << 17;
Point P[MAX];

int dist(const Point &A, const Point &B) {
    int dx = A.X - B.X;
    int dy = A.Y - B.Y;
    return abs(dx) + abs(dy);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        P[i] = { x, y };
    }

    int total = dist(P[0], P[1]);
    int skip = 0;

    for (int i = 1; i < N-1; i++) {
        int prev = dist(P[i-1], P[i]);
        int next = dist(P[i], P[i+1]);
        int jump = dist(P[i-1], P[i+1]);
        
        total += next;
        
        int diff = prev + next - jump;
        skip = max(skip, prev + next - jump);
    }

    int res = total - skip;
    cout << res << '\n';
    return 0;
}
