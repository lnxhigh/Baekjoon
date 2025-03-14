#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N, H;
int D[2][500001];

int main() {
    FastIO
    cin >> N >> H;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        D[i & 1][x]++;
    }

    int ans = N + 1;
    int cnt = 0;
    int sum = (N + 1) / 2;

    for (int h = 0; h < H; h++) {
        sum -= D[0][h];
        sum += D[1][H - h];

        if (sum < ans) ans = sum, cnt = 1;
        else if (sum == ans) cnt++;
    }

    cout << ans << ' ' << cnt << '\n';
    return 0;
}
