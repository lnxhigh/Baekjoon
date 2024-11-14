#include <bits/stdc++.h>
using namespace std;

int main() {
    double N, L, W, H; 
    cin >> N >> L >> W >> H;

    double low = 0;
    double high = min({ L, W, H });
    double ans = -1;
    
    for (int i = 0; i < 100; i++) {
        double A = (low + high) / 2.0;
        double cnt = floor(L / A) * floor(W / A) * floor(H / A);
        if (cnt >= N) ans = A, low = A;
        else high = A;
    }

    cout << fixed << setprecision(16);
    cout << ans << '\n';
    return 0;
}
