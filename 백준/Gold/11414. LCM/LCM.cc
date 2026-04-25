#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    int64 A, B; 
    cin >> A >> B;
    
    set<int64> D;
    int64 diff = abs(A - B);

    for (int64 i = 1; i * i <= diff; i++) {
        if (diff % i == 0) {
            D.insert(i);
            D.insert(diff / i);
        }
    }

    int64 N_ = 1;
    int64 L_ = (A + 1) * (B + 1);

    for (int64 G : D) {
        int64 N = G - A % G; // N = -A (mod G)
        int64 X = A + N, Y = B + N;
        int64 L = X * Y / G;
        if (L <= L_) { L_ = L; N_ = N; }
    }

    cout << N_ << '\n';
    return 0;
}
