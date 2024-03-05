#include <iostream>
#define M_MAX 10000
#define ll long long
#define X 1000000007LL
using namespace std;

ll M;
ll N[M_MAX+1];
ll S[M_MAX+1];
ll answer = 0LL;

ll power(ll a, ll p) {
    if (p == 0LL) return 1;
    else if (p == 1LL) return a % X;

    ll root = power(a, p / 2LL);
    ll res = (root * root) % X;
    if (p % 2LL == 0LL) return res;
    else return (a * res) % X;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> M;
    for (ll i = 0LL; i < M; i++) {
        cin >> N[i] >> S[i];
    }

    for (ll i = 0LL; i < M; i++) {
        ll a = S[i], b = N[i];
        ll b_inv = power(b, X-2LL);
        ll Q = (a * b_inv) % X;
        answer = (answer + Q) % X;        
    }

    cout << answer << '\n';
    
    return 0;
}