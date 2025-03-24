#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int R, C, K, N;
pair<int,int> Data[MAX];

int main() {
    FastIO

    cin >> R >> C;
    cin >> K >> N;

    int lo = 0, hi = 0;

    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        Data[i] = { y, x };

        lo = max(lo, x);
        hi = max(hi, max(x, y));
    }
    sort(Data, Data + N);

    int ans = hi;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int idx = 0, rem = K;
        int cover = 0;

        while (idx < N && rem) {
            rem--;
            cover = Data[idx].first + mid;
            while (idx < N && Data[idx].first < cover) idx++;
        }

        if (idx == N) ans = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}
