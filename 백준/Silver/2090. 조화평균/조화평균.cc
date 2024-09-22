#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    int N; cin >> N;
    vector<int64> A(N);
    for (int64 &k : A) cin >> k;

    int64 X = 1, Y = 0;
    for (int64 k : A) X = lcm(X, k);
    for (int64 k : A) Y += X / k;

    int64 D = gcd(X, Y);
    X /= D; Y /= D;
    cout << X << '/' << Y << '\n';

    return 0;
}
