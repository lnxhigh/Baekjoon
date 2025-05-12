#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int n, k;
int arr[250'001];
int tree[65'537];

int sum(int i) {
    int x = 0;
    while (i) x += tree[i], i -= i & -i;
    return x;
}

void update(int i, int x) {
    while (i <= 65536) tree[i] += x, i += i & -i;
}

int median(int m) {
    int x = 0;
    int lo = 0, hi = 65536;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (sum(mid) < m) x = mid, lo = mid + 1;
        else hi = mid - 1;
    }

    return x;
}

int main() {
    FastIO

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x; cin >> x; x++;
        arr[i] = x;
    }
    
    for (int i = 0; i < k; i++) {
        update(arr[i], 1);
    }

    int m = (k + 1) / 2;
    long long ans = median(m);
    
    for (int i = k; i < n; i++) {
        update(arr[i], 1);
        update(arr[i - k], -1);
        ans += median(m);
    }

    cout << ans << '\n';
    return 0;
}
