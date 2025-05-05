#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 6;

int n;
int arr[MAX];

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr[i] = b - a;
    }

    sort(arr, arr + n);
    
    int m = (n / 2) - 1;
    int ans = (n & 1) ? 1 : arr[m + 1] - arr[m] + 1;
    cout << ans << '\n';

    return 0;
}
