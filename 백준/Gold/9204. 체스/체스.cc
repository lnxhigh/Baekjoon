#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

void print(int x, int y) {
    cout << (char) ('A' + x) << ' ';
    cout << (char) ('1' + y) << ' ';
}

void solve(int a, int b, int x, int y) {
    if ((a + b) % 2 != (x + y) % 2) {
        cout << "Impossible" << '\n';
    }
    else {
        if (a == x && b == y) {
            cout << 0 << ' ';
            print(x, y);
            cout << '\n';
        }
        else if (abs(a - x) == abs(b - y)) {
            cout << 1 << ' ';
            print(a, b);
            print(x, y);
            cout << '\n';
        }
        else {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if ((abs(i - a) == abs(j - b)) && (abs(i - x) == abs(j - y))) {
                        cout << 2 << ' ';
                        print(a, b);
                        print(i, j);
                        print(x, y);
                        cout << '\n';
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    FastIO
    int tc; cin >> tc;
    while (tc--) {
        char a, b, c, d;
        cin >> a >> b >> c >> d;
        solve(a - 'A', b - '1', c - 'A', d - '1');
    }

    return 0;
}
