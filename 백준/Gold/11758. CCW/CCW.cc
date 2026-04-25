#include <iostream>

using namespace std;

int x1, x2, x3;
int y1, y2, y3;
int det, dir;

int main(void) {
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    det = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (det > 0) dir = 1;
    else if (det < 0) dir = -1;
    else dir = 0;

    cout << dir;

    return 0;
}