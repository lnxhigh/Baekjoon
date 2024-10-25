#include <bits/stdc++.h>
using namespace std;

int main() {
    double N; cin >> N;
    double m1 = 1, m2 = N * N;

    double x1 = (m1 - m2) / (m1 + m2);
    double y1 = (m2 + m2) / (m1 + m2);
    double x2 = (m1 + m1) / (m1 + m2);
    double y2 = (m2 - m1) / (m1 + m2);

    double u1 = 0, u2 = -1;
    int col = 0;

    while (true) {
        // Collision of A and B
        col++;

        // New Velocity
        double v1 = x1 * u1 + y1 * u2;
        double v2 = x2 * u1 + y2 * u2;
        u1 = v1, u2 = v2;
        if (u1 == 0) break;

        // Collision with Wall
        if (u1 < 0) u1 = abs(u1), col++;
        if (u2 > 0 && u1 <= u2) break;
    }

    cout << col << '\n';
    return 0;
}
