#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

int64 N;
int64 A, B, C, D;

int64 ceil(int64 a, int64 b) {
    int64 x = a / b;
    if (a % b != 0) x++;
    return x;
}

int main() {
    FastIO
    cin >> N;
    cin >> A >> B >> C >> D;

    int64 ans = LLONG_MAX;
    for (int64 i = 0; i <= C; i++) {
        int64 j = ceil(max(N - A * i, 0LL), C);
        ans = min(ans, B * i + D * j);
    }
    for (int64 j = 0; j <= A; j++) {
        int64 i = ceil(max(N - C * j, 0LL), A);
        ans = min(ans, B * i + D * j);
    }
    cout << ans << '\n';

    return 0;
}
