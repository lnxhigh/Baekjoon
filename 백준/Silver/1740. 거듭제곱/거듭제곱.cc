#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
int64 N, X;

int main() {
    cin >> N;
    for (int64 i = N, k = 1; i; i >>= 1, k *= 3) {
        X += k * (i & 1);
    }
    cout << X << '\n';
    return 0;
}
