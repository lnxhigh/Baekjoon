#include <bits/stdc++.h>
using namespace std;
using int64 = unsigned long long;

int64 f(int64 x) {
    int64 r = x % 4;
    if (r == 1) return 1;
    else if (r == 2) return x + 1;
    else if (r == 3) return 0;
    return x;
}

int main() {
    int64 A, B; cin >> A >> B;
    int64 X = f(A - 1) ^ f(B);
    cout << X << '\n';
    return 0;
}
