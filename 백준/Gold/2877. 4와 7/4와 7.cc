#include <bits/stdc++.h>
using namespace std;

string f(int x) {
    if (x == 1) return "";
    
    int i = 30;
    while (!(x >> i & 1)) i--;

    int j = i - 1;
    string p = (x >> j & 1) ? "7" : "4";
    
    x &= ~(1 << i), x |= (1 << j);
    return p + f(x);
}

int main() {
    int K; cin >> K;
    cout << f(++K) << '\n';
    return 0;
}
