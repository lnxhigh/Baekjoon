#include <bits/stdc++.h>
using namespace std;
using Point = pair<int,int>;

int K;
const int N = 6;
pair<int,int> data_[N];
Point loc[N];

int dx[5] = { 0, 0, 0, -1, +1 };
int dy[5] = { 0, +1, -1, 0, 0 };

int main() {
    cin >> K;
    for (int i = 0; i < N; i++) {
        int dir, len;
        cin >> dir >> len;
        data_[i] = { dir, len };
    }

    loc[0] = { 0, 0 };
    for (int i = 0; i < N-1; i++) {
        int dir = data_[i].first;
        int len = data_[i].second;
        loc[i+1] = { loc[i].first + dx[dir] * len, loc[i].second + dy[dir] * len};
    }

    const int INF = 1 << 20;
    int minX = INF, maxX = 0, minY = INF, maxY = 0;

    for (int i = 0; i < N; i++) {
        minX = min(minX, loc[i].first);
        maxX = max(maxX, loc[i].first);
        minY = min(minY, loc[i].second);
        maxY = max(maxY, loc[i].second);
    }

    int sub = 0;
    for (int i = 0; i < N; i++) {
        int x = loc[i].first, y = loc[i].second;
        if (x > minX && x < maxX && y > minY && y < maxY) {
            sub = data_[i].second * data_[(i+5) % N].second;
            break;
        }
    }

    int area = (maxX - minX) * (maxY - minY) - sub;
    area *= K;
    cout << area << '\n';
    return 0;
}
