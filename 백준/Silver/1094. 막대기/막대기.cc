#include <bits/stdc++.h>
using namespace std;

int X, K;

int main() {
    cin >> X;
    for (int i = 0; i <= 6; i++) { K += (X & (1 << i)) >> i; }
    cout << K << '\n';
    return 0;
}
