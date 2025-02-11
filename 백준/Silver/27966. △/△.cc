#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int N; cin >> N;
    cout << (long long) (N - 1) * (N - 1) << '\n';
    for (int i = 2; i <= N; i++) {
        cout << 1 << ' ' << i << '\n';
    }
    return 0;
}
