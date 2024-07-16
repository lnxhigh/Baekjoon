#include <bits/stdc++.h>
using namespace std;

int N, R1, C1, R2, C2;

char f(int x, int y, int N) {
    x %= 2 * N + 1;
    y %= 2 * N + 1;

    int d = abs(x - N) + abs(y - N);
    if (d > N) return '.';

    d %= 26;
    return 'a' + d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> R1 >> C1 >> R2 >> C2;

    --N;
    for (int x = R1; x <= R2; x++) {
        for (int y = C1; y <= C2; y++) {
            cout << f(x, y, N);
        }
        cout << '\n';
    }
    return 0;
}
