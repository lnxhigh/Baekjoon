#include <bits/stdc++.h>
using namespace std;

int factorize(int x) {
    int last = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i != 0) continue;
        last = i;
        while (x % i == 0) x /= i;
    }
    
    return max(last, x);
}

int solve(int n) {
    int x = 1;
    int p = factorize(n);
    if (p == 1) return 1;

    int cnt = 0;
    while (n % p == 0) { cnt++; n /= p; }
    if (cnt % 2 == 0) return 0;
    
    if (n % (p - 1) != 0) return 0;
    n /= p - 1;
    
    cnt = (cnt + 1) / 2;
    while (cnt--) x *= p;

    return x * solve(n);
}

int main() {
    int n; cin >> n;
    int x = solve(n);
    if (!x) x = -1;
    cout << x << '\n';
    return 0;
}
