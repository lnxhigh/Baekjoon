#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO

    int N, A, B;
    cin >> N >> A >> B;
    int diff = N - (A + B - 1);

    if (diff < 0) {
        cout << -1 << '\n';
        return 0;
    }

    if (A == 1) {
        cout << B << ' ';
        for (int i = 1; i <= diff; i++) {
            cout << 1 << ' ';
        }
        for (int i = B - 1; i > 0; i--) {
            cout << i << ' ';
        }
        
        return 0;
    }

    // Init
    for (int i = 1; i <= diff; i++) {
        cout << 1 << ' ';
    }

    // Left
    for (int i = 1; i < A; i++) {
        cout << i << ' ';
    }

    // Mid
    cout << max(A, B) << ' ';

    // Right
    for (int i = B - 1; i > 0; i--) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}
