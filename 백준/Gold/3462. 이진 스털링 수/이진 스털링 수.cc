#include <iostream>
using namespace std;

int D;
int n, m;

int binaryStirling(int n, int m) {
    if (n == 0 and m == 0) return 1;
    else if (n == 0 or m == 0) return 0;
    else if (n < m) return 0;
    
    if (m % 2 == 0) return binaryStirling(n-1, m-1);
    if (((m/2) & (n-m)) == 0) return 1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> D;
    for (int d = 0; d < D; d++) {
        cin >> n >> m;
        cout << binaryStirling(n, m) << '\n';
    }
    return 0;
}