#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int iter = N / 3;

    int res = 1;
    for (int i = 0; i < N / 3; i++) {
        int s = 2 * i + 1;
        res += s + (s + 1) + (s + 2);
    }

    for (int i = 0; i < N % 3; i++) {
        int s = 2 * (N / 3) + 1;
        res += s + i;
    }

    cout << res << '\n';
    return 0;
}
