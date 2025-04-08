#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 16;

int n, d, k, c;

int arr[60001];
int type[3001];

int main() {
    FastIO
    cin >> n >> d >> k >> c;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr[i] = arr[i + n] = x;
    }

    for (int i = 0; i < k; i++) {
        type[arr[i]]++;
    }
    type[c]++;

    int cnt = 0;
    for (int i = 0; i <= d; i++) {
        if (type[i]) cnt++;
    }

    int ans = cnt;

    for (int i = 0; i < n; i++) {
        if (type[arr[k + i]]++ == 0) cnt++;
        if (--type[arr[i]] == 0) cnt--;
        ans = max(ans, cnt);
    }

    cout << ans << '\n';

    return 0;
}
