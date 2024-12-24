#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int N; cin >> N;
    cout << N << '\n';
    
    if (N % 3 == 0) {
        // 1 3 2    4 6 5    7 9 8    1
        for (int i = 1; i + 2 <= N; i += 3) {
            cout << i << ' ' << i + 2 << ' ' << i + 1 << ' ';
        }
    }
    else if (N % 3 == 1) {
        // 1    2 4 3    5 7 6    1
        cout << 1 << ' ';
        for (int i = 2; i + 2 <= N; i += 3) {
            cout << i << ' ' << i + 2 << ' ' << i + 1 << ' ';
        }
    }
    else if (N % 3 == 2) {
        // 1 2    4 3 5    7 6 8    1
        cout << 1 << ' ' << 2 << ' ';
        for (int i = 4; i + 1 <= N; i += 3) {
            cout << i << ' ' << i - 1 << ' ' << i + 1 << ' ';
        }
    }
    cout << 1 << '\n';

    return 0;
}
