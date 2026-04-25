#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

double f(int64 R, int64 A, int64 D, int64 K) {
    int64 T = R + A;
    
    double ret = 0;
    ret += (K / T) * D;

    K %= T; K -= R;
    if (K <= 0) return ret;

    double p = (double) K / (double) A;
    ret += p * D;

    return ret;
}

int main() {
    FastIO
    int64 N, S, E;
    cin >> N >> S >> E;

    double ans = 0;
    for (int i = 0; i < N; i++) {
        int64 R, A, D;
        cin >> R >> A >> D;    
        ans += f(R, A, D, E);
        ans -= f(R, A, D, S);
    }

    ans /= (double) E - (double) S;
    cout << setprecision(16);
    cout << ans << '\n';
    return 0;
}
