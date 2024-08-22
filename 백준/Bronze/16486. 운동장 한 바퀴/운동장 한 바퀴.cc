#include <bits/stdc++.h>
using namespace std;

double D, R;
const double PI = 3.141592;

int main() {
    cin >> D >> R;
    double X = 2.0 * PI * R + 2.0 * D;
    cout << setprecision(16);
    cout << X << '\n';
    return 0;
}
