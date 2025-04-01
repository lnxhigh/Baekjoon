#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using Point = pair<int,int>;
const int MAX = 5001;

int N, K;
Point Data[MAX];
set<pair<Point,Point>> Holes;

int maxH[MAX];

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        Data[i] = { x, y };
    }

    cin >> K;
    for (int i = 0; i < K; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        Point x = { a, b }, y = { c, d };
        Holes.insert({ x, y });
    }

    for (int i = 1; i < N; i += 2) {
        bool isHole = Holes.count({ Data[i], Data[i + 1] });
        if (!isHole) continue;

        int limit = Data[i].second;
        for (int j = i; j > 0; j -= 2) {
            limit = min(limit, Data[j].second);
            maxH[j] = max(maxH[j], limit);
        }

        limit = Data[i].second;
        for (int j = i; j < N; j += 2) {
            limit = min(limit, Data[j].second);
            maxH[j] = max(maxH[j], limit);
        }
    }

    int ans = 0;

    for (int i = 1; i < N; i += 2) {
        int width = Data[i + 1].first - Data[i].first;
        int height = Data[i].second - maxH[i];
        int area = width * height;
        
        ans += area;
    }

    cout << ans << '\n';
    return 0;
}
