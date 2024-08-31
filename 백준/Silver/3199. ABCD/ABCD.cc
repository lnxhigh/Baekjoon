#include <bits/stdc++.h>
using namespace std;

int main() {
    double p, q, r;
    cin >> p >> q >> r;
    
    if (p != r) cout << 0 << '\n';
    else cout << fixed << setprecision(4) << p * (q + r) * 2.0 << '\n';
    return 0;
}
