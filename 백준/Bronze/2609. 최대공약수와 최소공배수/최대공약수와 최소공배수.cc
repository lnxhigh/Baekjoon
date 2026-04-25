#include <iostream>
using namespace std;

int x, y;

int gcd(int x, int y) {
    if (not y) return x;
    return gcd(y, x % y);
}

int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

int main(void) {
    cin >> x >> y;
    cout << gcd(x, y) << '\n';
    cout << lcm(x, y) << '\n';
    return 0;
}