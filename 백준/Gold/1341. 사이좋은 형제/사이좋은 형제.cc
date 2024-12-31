#include <bits/stdc++.h>
using namespace std;
using int64 = unsigned long long;

void solve(int64 A, int64 B) {
    for (int len = 1; len <= 60; len++) {
        int64 X = (1LL << len) - 1LL;
        if (X % B != 0) continue;
        A *= X / B;
        
        int i = len;
        while (i--) cout << ((A >> i & 1) ? '*' : '-');
        return;
    }

    cout << -1;
    return;
}

int main() {
    int64 A, B;
    cin >> A >> B;
    solve(A, B);
    return 0;
}
