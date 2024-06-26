#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
const int L = 10;

ll A[10];
vector<ll> V;

int main() {
    cin >> N;
    for (int i = 0; i < L; i++) {
        A[i] = i;
    }
    
    for (int i = 1; i < (1 << L); i++) {
        ll res = 0, mul = 1;
        for (int k = 0; k < L; k++) {
            if (i & (1 << k)) {
                res += A[k] * mul;
                mul *= 10;
            }
        }
        V.push_back(res);
    }

    sort(V.begin(), V.end());
    int S = V.size();
    ll ans = (N < S) ? V[N] : -1;
    cout << ans << '\n';
    
    return 0;
}
