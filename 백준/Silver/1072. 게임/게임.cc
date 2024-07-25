#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll X, Y;

ll F(ll X, ll Y) {
    ll Z = Y * 100 / X;
    ll A = 99LL - Z;
    ll B = X * (Z + 1) - Y * 100;
    if (A <= 0) return -1LL;
    return (A + B - 1) / A;
}

int main()
{
    cin >> X >> Y;
    ll K = F(X, Y);
    cout << K << '\n';
    return 0;
}
