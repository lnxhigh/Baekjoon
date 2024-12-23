#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int64 INF = LLONG_MAX;

int64 L, K;
vector<int64> S;
map<int64,int64> M;

void input() {
    cin >> L;
    S.resize(L + 2);

    S[0] = 0;
    for (int i = 1; i <= L; i++) {
        cin >> S[i];
    }
    S[L + 1] = INF;
    sort(S.begin(), S.end());
    
    cin >> K;
}

void solve() {
    for (int64 i = 0; i <= L; i++) {
        for (int64 x = S[i] - K; x <= S[i] + K; x++) {
            if (x <= 0) continue;
            auto high = lower_bound(S.begin(), S.end(), x);
            assert(high != S.begin() && high != S.end());
            auto low = prev(high);
            
            int64 cnt = 0;
            if (*high == x) cnt = 0;
            else if (*high < INF) cnt = (*high - x) * (x - *low) - 1;
            else cnt = INF;
            M[x] = cnt;
        }
    }

    vector<pair<int64,int64>> V;
    V.reserve(L * (2 * K + 1));
    for (auto [x, cnt] : M) {
        V.push_back({ cnt, x });
    }
    assert((int) V.size() >= K);
    sort(V.begin(), V.end());

    for (int i = 0; i < K; i++) {
        auto [cnt, x] = V[i];
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    FastIO
    input();
    solve();
    return 0;
}
