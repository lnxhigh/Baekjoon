#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 250'005;

int n;
int arr[MAX];
int h[MAX], l[MAX], r[MAX];

// Doubly linked list
int a[MAX], b[MAX];

int main() {
    FastIO
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        arr[i] = x + 1;
        a[i] = i - 1, b[i] = i + 1;
    }
    
    long long ans = 0;

    for (int i = n; i > 0; i--) {
        int x = arr[i];
        l[x] = a[x], r[x] = b[x];
        a[b[x]] = a[x], b[a[x]] = b[x];
    }

    for (int i = 1; i <= n; i++) {
        int x = arr[i];
        h[x] = max(h[l[x]], h[r[x]]) + 1;
        ans += h[x];
    }

    cout << ans << '\n';
    return 0;
}
