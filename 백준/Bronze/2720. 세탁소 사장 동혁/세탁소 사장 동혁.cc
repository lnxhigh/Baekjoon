#include <bits/stdc++.h>
using namespace std;

int T, C;
int A[4] = { 25, 10, 5, 1 };

void solve(int X) {
    for (int i = 0; i < 4; i++) {
        cout << X / A[i] << ' ';
        X %= A[i];
    }
    cout << '\n';
    return;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> C;
        solve(C);
    }
    return 0;
}
