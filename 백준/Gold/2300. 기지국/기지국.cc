#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
#define X first
#define Y second
using namespace std;
using Point = pair<int,int>;

int N;
const int INF = 1 << 20;

int main() {
    FastIO
    
    cin >> N;
    vector<Point> P(N);
    for (auto &[x,y] : P) { cin >> x >> y; }
    sort(P.begin(), P.end());

    vector<int> D(N+1, INF);
    D[0] = 0;

    for (int i = 1; i <= N; i++) {
        vector<int> H(i+1);
        for (int k = i-1; k >= 0; k--) {
            H[k] = max(H[k+1], abs(P[k].Y));
        }

        for (int k = 0; k < i; k++) {
            int len = max(P[i-1].X - P[k].X, H[k] << 1);
            D[i] = min(D[i], D[k] + len);
        }
    }

    cout << D[N] << '\n';
    return 0;
}
