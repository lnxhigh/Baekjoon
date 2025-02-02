#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const double PI = acos(-1);

int main() {
    FastIO
    int T; cin >> T;
    cout << fixed << setprecision(5);
    
    while (T--) {
        double ans = 0;
        int N; cin >> N;

        for (int i = 0; i < N; i++) {
            int X1, Y1, X2, Y2; 
            cin >> X1 >> Y1 >> X2 >> Y2;

            double dot = X1 * X2 + Y1 * Y2;
            double x = sqrt(X1 * X1 + Y1 * Y1);
            double y = sqrt(X2 * X2 + Y2 * Y2);
        
            double value = dot / (x * y);
            double theta = acos(clamp(value, -1.0, 1.0));
            ans += theta / (2.0 * PI);
        }

        cout << ans << '\n';
    }

    return 0;
}
