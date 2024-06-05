#include <bits/stdc++.h>
using namespace std;

// 또다른 반례가 있는 것인지 아님 정밀도 문제인지
double X, Y, D, T;

double solve(double X, double Y, double D, double T) {
    double dist = sqrt(X*X + Y*Y);
    if (dist <= T || D <= T) return dist;
    if (dist <= D) return min({ dist, T + D - dist, T*2 });

    int K = floor(dist / D);
    return min({ dist, T*K + dist - D*K, T*(K+1) });
}

int main() {
    cin >> X >> Y >> D >> T;
    cout.precision(16);
    cout << solve(X, Y, D, T) << '\n';
    return 0;
}
