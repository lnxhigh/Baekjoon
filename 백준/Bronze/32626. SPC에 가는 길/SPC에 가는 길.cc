#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
int64 sx, sy, ex, ey, px, py;

int solve() {
    if (sx == ex) {
        if (px != sx) return 0;
        return (py - sy) * (py - ey) < 0 ? 2 : 0;
    }
    if (sy == ey) {
        if (py != sy) return 0;
        return (px - sx) * (px - ex) < 0 ? 2 : 0;
    }

    return 1;
}

int main() {
    cin >> sx >> sy;
    cin >> ex >> ey;
    cin >> px >> py;
    
    cout << solve() << '\n';
    return 0;    
}
