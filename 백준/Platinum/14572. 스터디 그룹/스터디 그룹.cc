#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100'000;

int n, k, d;
pair<int,int> arr[MAX];
int chk[32];

void f(int idx, bool flag) {
    int x = arr[idx].second;
    int add = flag ? 1 : -1;

    for (int i = 0; i < k; i++) {
        if (x >> i & 1) chk[i] += add;
    }
}

int main() {
    FastIO

    cin >> n >> k >> d;

    for (int i = 0; i < n; i++) {
        int m = 0, s = 0, x = 0, a = 0;
        cin >> m >> s;
        while (m--) cin >> a, x |= (1 << (--a));
        arr[i] = { s, x };
    }

    sort(arr, arr + n);

    int ans = 0;
    int lo = 0, hi = 0;
    f(0, true);

    while (hi < n) {
        while (hi + 1 < n && arr[hi + 1].first - arr[lo].first <= d) f(++hi, true);

        int cnt = 0;
        int group = hi - lo + 1;

        for (int i = 0; i < k; i++) {
            if (chk[i] == 0) continue;
            else if (chk[i] < group) cnt++;
        }

        ans = max(ans, cnt * group);
        f(lo++, false);

        if (hi == n - 1) break;
    }

    cout << ans << '\n';
    return 0;
}
