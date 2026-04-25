#include <iostream>
#include <cmath>
using namespace std;

int N;

int main(void) {
    cin >> N;
    if (not N) { cout << 1; }
    else { cout << ceil((-3.0 + sqrt(12.0 * N - 3.0)) / 6.0) + 1; }
    return 0;
}