#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;
ll A[1000000];
ll B, C;

ll f(ll k) {
    if (k <= B) return 1;
    return (k - B - 1) / C + 1 + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> B >> C;
    
    ll res = 0;
    for (ll i = 0; i < N; i++) {
        res += f(A[i]);
    }
    cout << res << '\n';
    
    return 0;
}