#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 200'001;
const int MOD = 40'000;

int n;
tuple<double,int,int> arr[MAX];

int main() {
    FastIO
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        double x = a ? (double) b / (double) a : 1e9;
        arr[i] = { x, a, b };
    }

    sort(arr, arr + n);

    int t = 0;
    for (int i = 0; i < n; i++) {
        auto [x, a, b] = arr[i];
        t += (a * t + b) % MOD;
        t %= MOD;
    }
    
    cout << t << '\n';
    return 0;
}
