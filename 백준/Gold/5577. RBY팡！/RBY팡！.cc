#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int n;
vector<int> arr;

int f(int idx) {
    int ret = n;
    int l = idx, r = idx;

    while (l >= 0 && r < n) {
        if (arr[l] != arr[r]) break;
        int cnt = (l == r) ? 1 : 2;

        while (l > 0 && arr[l - 1] == arr[l]) l--, cnt++;
        while (r < n - 1 && arr[r + 1] == arr[r]) r++, cnt++;

        if (cnt < 4) break;
        ret -= cnt;
        l--, r++;
    }

    return ret;
}

int main() {
    FastIO

    cin >> n;
    arr.resize(n);
    for (int& x : arr) cin >> x;

    int ans = n;

    for (int i = 0; i < n; i++) {
        for (int k = 1; k <= 3; k++) {
            if (k == arr[i]) continue;

            int x = arr[i];
            arr[i] = k;

            ans = min(ans, f(i));
            arr[i] = x;
        }
    }

    cout << ans << '\n';
    return 0;
}
