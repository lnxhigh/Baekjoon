#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const double PI = acos(-1);

double r, p, d1, a1, d2, a2;

double solve() {
    double theta = abs(a2 - a1) / 180.0 * PI;
    theta = min(theta, 2.0 * PI - theta);
    
    double h = sqrt(r * r + p * p);
    double phi = (r * theta) / h;
    
    double len = sqrt(d1 * d1 + d2 * d2 - 2.0 * d1 * d2 * cos(phi));
    return len;
}

int main() {
    FastIO
    cout << fixed << setprecision(2);

    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        double arr[6] = {0.0};

        for (int i = 0; i < 6; i++) {
            string word;
            getline(ss, word, ' ');
            arr[i] = stod(word);
        }
        
        r = arr[0], p = arr[1];
        d1 = arr[2], a1 = arr[3];
        d2 = arr[4], a2 = arr[5];

        double ans = solve();
        cout << ans << '\n';
    }
    
    return 0;
}
