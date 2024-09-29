#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

void factorize(int X) {
    for (int i = 2; i <= X; i++) {
        if (X % i != 0) continue;

        int cnt = 0;
        while (X % i == 0) { cnt++; X /= i; }
        cout << i << ' ' << cnt << '\n';
    }
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        factorize(N);
    }
    return 0;
}
