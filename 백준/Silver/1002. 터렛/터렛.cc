#include <bits/stdc++.h>
using namespace std;

int TC;
int X1, Y1, R1;
int X2, Y2, R2;

struct Turret {
    int X, Y, R;
    Turret(int x, int y, int r) : X(x), Y(y), R(r) { }
    bool operator==(const Turret &other) {
        return X == other.X && Y == other.Y && R == other.R;
    }
};

int solve(Turret A, Turret B) {
    if (A == B) return -1;

    int dx = A.X - B.X, dy = A.Y - B.Y;
    int sumR  = A.R + B.R, diffR = A.R - B.R;
    int dist2 = dx*dx + dy*dy;

    if (dist2 > sumR * sumR) return 0;
    else if (dist2 == sumR * sumR) return 1;
    
    if (dist2 < diffR * diffR) return 0;
    else if (dist2 == diffR * diffR) return 1;
    
    return 2;
}

int main() {
    cin >> TC;
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while (TC--) {
        cin >> X1 >> Y1 >> R1;
        cin >> X2 >> Y2 >> R2;
        Turret A(X1, Y1, R1);
        Turret B(X2, Y2, R2);
        int res = solve(A, B);
        cout << res << '\n';
    }

    return 0;
}
