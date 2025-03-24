#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 101;

int W, H, L, K;
pair<int,int> Data[MAX];

int main() {
    FastIO
    cin >> W >> H >> L >> K;
    for (int i = 0; i < K; i++) {
        int x, y; cin >> x >> y;
        Data[i] = { x, y };
    }

    int ans = 0;

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            int cnt = 0;
            int xmin = Data[i].first, ymin = Data[j].second;
            int xmax = xmin + L, ymax = ymin + L;

            for (int k = 0; k < K; k++) {
                auto [x, y] = Data[k];
                if (x >= xmin && x <= xmax && y >= ymin && y <= ymax) cnt++;
            }

            ans = max(ans, cnt);
        }
    }

    ans = K - ans;
    cout << ans << '\n';
    return 0;
}
