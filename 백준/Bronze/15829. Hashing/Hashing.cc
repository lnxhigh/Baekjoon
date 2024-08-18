#include <bits/stdc++.h>
using namespace std;

string S;
int L;
const long long r = 31, M = 1234567891;

int main() {
    cin >> L >> S;

    long long res = 0;
    for (int i = 0; i < L; i++) {
        long long a = (long long) (S[i] - 'a') + 1;

        long long mul = 1;
        for (int p = 0; p < i; p++) {
            mul = (mul * r) % M;
        }

        res += a * mul;
        res %= M;
    }

    cout << res << '\n';
    return 0;
}
