#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int N; cin >> N; N--;
    int r; cin >> r;

    while (N--) {
        int x; cin >> x;
        int g = gcd(r, x);
        cout << (r / g) << '/' << (x / g) << '\n';
    }

    return 0;
}
