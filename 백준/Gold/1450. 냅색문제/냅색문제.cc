#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, C;
const int N_MAX = 30;
ll A[N_MAX];

vector<ll> Left, Right;

void f(int S, int E, vector<ll> &V) {
    int K = E - S + 1;
    if (K < 0) return;

    for (int bits = 0; bits < (1 << K); bits++) {
        ll sum = 0;
        for (int i = 0; i < K; i++) {
            if (bits & (1 << i)) { sum += A[S + i]; }
        }
        V.push_back(sum);
    }
}

int MITM(const vector<ll> &Left, const vector<ll> &Right, ll C) {
    int res = 0;
    for (ll x : Left) {
        ll y = C - x;
        int cnt = upper_bound(Right.begin(), Right.end(), y) - Right.begin();
        res += cnt;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int L = (N-1) / 2;
    int R = N - L;

    f(0, L, Left);
    f(L + 1, N - 1, Right);
    
    sort(Left.begin(), Left.end());
    sort(Right.begin(), Right.end());

    int res = MITM(Left, Right, 1LL * C);
    cout << res << '\n';

    return 0;
}
