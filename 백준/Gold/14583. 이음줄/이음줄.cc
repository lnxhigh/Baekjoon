#include <bits/stdc++.h>
using namespace std;

int main() {
    double H, V;
    cin >> H >> V;
    
    double D = sqrt(H*H + V*V);
    double X = H / V * (D - H);
    double S = 0.5 * D * X;
    
    double A = 0.5 * sqrt(H*H + X*X);
    double B = S / A;
    cout << fixed << setprecision(2);
    cout << A << ' ' << B << '\n';
    return 0;
}
