#include <bits/stdc++.h>
using namespace std;

string N;
int B;

int decode(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    return c - '0';
}

int main() {
    cin >> N >> B;
    int L = N.size();
    int res = 0, mul = 1;
    for (int i = L-1; i >= 0; i--) {
        res += decode(N[i]) * mul;
        mul *= B;
    }

    cout << res << '\n';
    return 0;
}
