#include <bits/stdc++.h>
using namespace std;

int main() {
    int M; cin >> M;
    int x = 180*M*M - 2*M*M*M, y = 216000;
    int d = gcd(x, y);
    x /= d, y /= d;
    cout << x << '/' << y << '\n';
}
