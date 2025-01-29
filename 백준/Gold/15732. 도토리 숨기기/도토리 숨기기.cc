#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int64 MAX = 10001;

int64 N, K, D;
tuple<int64,int64,int64> Rules[MAX];

int64 f(int64 x) {
    int64 cnt = 0;
    for (int64 i = 0; i < K; i++) {
        const auto& [A, B, C] = Rules[i];
        if (x < A) continue;
        cnt += (min(x, B) - A) / C + 1;
    }
    return cnt;
}

int main() {
    FastIO
    cin >> N >> K >> D;
    for (int64 i = 0; i < K; i++) {
        int64 A, B, C; cin >> A >> B >> C;
        Rules[i] = { A, B, C };
    }

    int64 ans = 0;
    int64 low = 1, high = N;
    while (low <= high) {
        int64 mid = (low + high) / 2;
        int64 cnt = f(mid);
        if (cnt < D) ans = mid, low = mid + 1;
        else high = mid - 1;
    }

    cout << ++ans << '\n';
    return 0;
}
