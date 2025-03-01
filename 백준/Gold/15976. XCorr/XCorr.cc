#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 300'001;

ll N, M, A, B;
ll Xidx[MAX], Yidx[MAX];
ll X[MAX], Y[MAX];
ll S[MAX];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> Xidx[i] >> X[i];
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> Yidx[i] >> Y[i];
    }

    cin >> A >> B;
}

ll f(ll target, ll* arr, ll size) {
    ll idx = -1;
    ll lo = 0, hi = size - 1;

    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (arr[mid] <= target) idx = mid, lo = mid + 1;
        else hi = mid - 1;
    }

    return idx;
}

ll solve() {
    S[0] = Y[0];
    for (int i = 1; i < M; i++) {
        S[i] = S[i - 1] + Y[i];
    }

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        ll lwr = f(Xidx[i] + A - 1, Yidx, M);
        ll upr = f(Xidx[i] + B, Yidx, M);

        ll sum = S[upr];
        if (lwr != -1) sum -= S[lwr];
        
        ans += X[i] * sum;
    }

    return ans;
}

int main() {
    FastIO
    input();

    ll ans = solve();
    cout << ans << '\n';
    return 0;
}
