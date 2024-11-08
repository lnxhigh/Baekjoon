#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    int64 k; cin >> k; --k;
    bool x = false;
    while (k) {
        if (k & 1) x ^= true;
        k >>= 1;
    }
    cout << x << '\n';
    return 0;
}
