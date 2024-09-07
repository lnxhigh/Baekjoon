#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K;
double a, b, c;

ll choose(ll n, ll k) {
    ll res = 1;
    k = min(k, n - k);

    for (ll i = 0; i < k; i++) {
        res *= n - i;
        res /= i + 1;
    }
    return res;
}

int main() {
    cin >> a >> b;
    cin >> N >> K;
    c = sqrt(a*a + b*b);

    double p = 2.0 * log(a / c);
    double q = 2.0 * log(b / c);

    vector<double> areas(N+1);
    for (ll i = 0; i <= N; i++) {
        double area = p * i + q * (N - i);
        areas[i] = area;
    }

    sort(areas.begin(), areas.end(), [] (double &x, double &y) {
        return x > y; 
    });
    
    double S = 0.5 * a * b;
    double res = log(S);
    ll cnt = 0;

    for (ll i = 0; i <= N; i++) {
        ll x = choose(N, i);
        if (K > cnt && K <= cnt + x) { res += areas[i]; break; }
        cnt += x;
    }

    cout << setprecision(16);
    cout << res << '\n';
    return 0;
}
