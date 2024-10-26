#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
int64 F[117];

int64 f(int n) {
    if (F[n]) return F[n];
    if (n <= 3) return F[n] = 1;
    return F[n] = f(n-1) + f(n-3);
}

int main() {
    int N; cin >> N;
    cout << f(N) << '\n';
    return 0;
}
