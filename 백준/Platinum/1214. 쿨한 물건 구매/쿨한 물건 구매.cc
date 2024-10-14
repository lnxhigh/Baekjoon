#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 ceil(int64 a, int64 b) {
    int64 x = a / b;
    if (a % b != 0) x++;
    return x;
}

int main() {
    // n * P + m * Q >= D
    int64 D, P, Q; 
    cin >> D >> P >> Q;

    int64 R = (int64) sqrt(D);
    int64 X = min(P * ceil(D, P), Q * ceil(D, Q));

    if (Q < R) {
        int64 L = min(ceil(D, P), Q);
        for (int64 n = 0; n < L; n++) {
            int64 m = ceil(D - n * P, Q);
            X = min(X, n * P + m * Q);
        }
    }
    else {
        int64 L = ceil(D, Q);
        for (int64 m = 0; m < L; m++) {
            int64 n = ceil(D - m * Q, P);
            X = min(X, n * P + m * Q);
        }
    }

    cout << X << '\n';
    return 0;
}
