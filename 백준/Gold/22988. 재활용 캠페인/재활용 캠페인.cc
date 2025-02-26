#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 100001;

int N;
ll X, C[MAX];

int main() {
    FastIO
    cin >> N >> X;

    for (int i = 0; i < N; i++) cin >> C[i];
    sort(C, C + N);

    int ans = 0, cnt = N;
    int l = 0, r = N - 1;
    ll T = (X / 2) + (X % 2);

    while (l <= r && C[r] >= X) ans++, cnt--, r--;
    while (l < r) (C[l] + C[r] >= T) ? ans++, cnt -= 2, l++, r-- : l++;
    ans += cnt / 3;

    cout << ans << '\n';
    return 0;
}
