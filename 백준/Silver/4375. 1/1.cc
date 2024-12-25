#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int f(int n) {
    int cnt = 0, r = 0;
    do {
        cnt++;
        r = (10 * r + 1) % n;
    } while (r);

    return cnt;
}

int main() {
    FastIO
    int N;
    while (cin >> N) {
        cout << f(N) << '\n';
    }
    return 0;
}
