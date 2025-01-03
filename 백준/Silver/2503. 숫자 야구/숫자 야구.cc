#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 105;

int N;
int A[MAX];
pair<int,int> D[MAX];

bool f(int k) {
    int a = (k / 100) % 10, b = (k / 10) % 10, c = (k % 10);
    if (a == 0 || b == 0 || c == 0) return false;
    if (a == b || b == c || c == a) return false;

    for (int i = 0; i < N; i++) {
        int strike = 0, ball = 0;
        int x = (A[i] / 100) % 10, y = (A[i] / 10) % 10, z = (A[i] % 10);

        if (x == a) strike++;
        else if (x == b || x == c) ball++;
        if (y == b) strike++;
        else if (y == c || y == a) ball++;
        if (z == c) strike++;
        else if (z == a || z == b) ball++;

        auto [__strike, __ball] = D[i];
        if (strike != __strike || ball != __ball) return false;
    }

    return true;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        int s, b; cin >> s >> b;
        D[i] = { s, b };
    }

    int cnt = 0;
    for (int i = 100; i < 1000; i++) {
        if (f(i)) cnt++;
    }

    cout << cnt << '\n';
    return 0;
}
