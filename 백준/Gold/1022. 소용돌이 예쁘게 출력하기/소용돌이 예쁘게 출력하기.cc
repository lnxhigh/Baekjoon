#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int f(int r, int c) {
    int k = max(abs(r), abs(c));
    int len = 2 * k + 1;

    if (r == k) return (len * len - k) + c;
    else if (c == -k) return (len * len - 3 * k) + r;
    else if (r == -k) return (len * len - 5 * k) - c;
    else if (c == k) return (len * len - 7 * k) - r;
    return 0;
}

int main() {
    FastIO
    
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    size_t width = 0;
    
    for (int r = r1; r <= r2; r++) {
        for (int c = c1; c <= c2; c++) {
            width = max(width, to_string(f(r, c)).size());
        }
    }

    for (int r = r1; r <= r2; r++) {
        for (int c = c1; c <= c2; c++) {
            cout << setw(width) << f(r, c) << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
