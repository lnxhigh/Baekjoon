#include <bits/stdc++.h>
using namespace std;

pair<int,int> solve(int X, int Y) {
    Y /= X;
    int M = sqrt(Y);
    for (int i = M; i >= 1; i--) {
        if (Y % i != 0) continue;
        if (__gcd(i, Y / i) == 1) {
            return { X * i, X * Y / i };
        }
    }
    return { -1, -1 };
}

int main() {
    int X, Y;
    cin >> X >> Y;
    auto p = solve(X, Y);
    cout << p.first << ' ' << p.second << '\n';
    return 0;
}
