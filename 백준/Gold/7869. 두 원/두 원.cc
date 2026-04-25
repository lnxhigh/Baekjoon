#include <iostream>
#include <iomanip>
#include <cmath>
#define M_PI 3.14159265358979323846
using namespace std;

double x1, y1_, r1;
double x2, y2, r2;
double d;
double area;

int main(void) {
    cin >> x1 >> y1_ >> r1;
    cin >> x2 >> y2 >> r2;

    d = sqrt((x1-x2)*(x1-x2) + (y1_-y2)*(y1_-y2));

    if (d > r1 + r2) { 
        area = 0.0;
    }
    else if (d > abs(r1 - r2)) {
        double p = (r1 + r2 + d) / 2.0;
        double S = sqrt(p*(p-r1)*(p-r2)*(p-d)); // Heron's formula
        double h = 2*S / d;
        double theta1 = 2 * asin(h/r1), theta2 = 2 * asin(h/r2);
    
        // Check acute or obtuse
        if (r1*r1+d*d < r2*r2) { theta1 = 2*M_PI - theta1; }
        if (r2*r2+d*d < r1*r1) { theta2 = 2*M_PI - theta2; }

        area = 0.5*r1*r1*(theta1 - sin(theta1)) + 0.5*r2*r2*(theta2 - sin(theta2));
    }
    else {
        int r = min(r1, r2);
        area = M_PI * r * r;
    }
    
    cout << fixed << setprecision(3) << area << '\n';

    return 0;
}