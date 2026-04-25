#include <iostream>
#include <iomanip>
#define ll long long
using namespace std;

ll x1, y11, x2, y2;
ll x3, y3, x4, y4;
ll a, b, c, d, e, f;
ll det, m, n;
ll temp;
double t, s;
ll precision = 12;

int main(void) {
    cin >> x1 >> y11 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    
    a = x2 - x1; b = -(x4 - x3);
    c = y2 - y11; d = -(y4 - y3);
    e = x3 - x1; f = y3 - y11;

    det = a*d - b*c;
    m = d*e - b*f; n = -c*e + a*f;

    if (det == 0) {
        if (m != 0 || n != 0) {
            cout << 0 << '\n';
            return 0;
        }

        if (x1 == x2 && x3 == x4) {
            // Swap
            if (y11 > y2) { 
                temp = x1; x1 = x2; x2 = temp; 
                temp = y11; y11 = y2; y2 = temp; 
            }
            if (y3 > y4) { 
                temp = x3; x3 = x4; x4 = temp; 
                temp = y3; y3 = y4; y4 = temp; 
            }

            // Check if there is an intersection point
            if (y3 <= y2 && y4 >= y11) {
                cout << 1 << '\n';
                if (y3 == y2) { cout << x2 << ' ' << y2 << '\n'; }
                if (y4 == y11) { cout << x1 << ' ' << y11 << '\n'; }
            }
            else {
                cout << 0 << '\n';
            }
        }
        else {
            // Swap
            if (x1 > x2) { 
                temp = x1; x1 = x2; x2 = temp; 
                temp = y11; y11 = y2; y2 = temp; 
            }
            if (x3 > x4) { 
                temp = x3; x3 = x4; x4 = temp; 
                temp = y3; y3 = y4; y4 = temp; 
            }

            // Check if there is an intersection point
            if (x3 <= x2 && x4 >= x1) {
                cout << 1 << '\n';
                if (x3 == x2) { cout << x2 << ' ' << y2 << '\n'; }
                if (x4 == x1) { cout << x1 << ' ' << y11 << '\n'; }
            }
            else {
                cout << 0 << '\n';
            }
        }
    }

    else {
        t = double (m) / double (det);
        s = double (n) / double (det);

        double p1 = x1*1.0 + a*t;
        double p2 = y11*1.0 + c*t;

        if ((t >= 0 && t <= 1) && (s >= 0 && s <= 1)) {
            cout << 1 << '\n';
            cout << fixed << setprecision(precision) << p1 << ' ' << p2 << '\n';
        }
        else { 
            cout << 0 << '\n'; 
        }

    }

    return 0;
}