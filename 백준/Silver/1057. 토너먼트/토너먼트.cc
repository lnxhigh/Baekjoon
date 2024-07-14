#include <bits/stdc++.h>
using namespace std;

int N, X, Y;

int main() {
    cin >> N >> X >> Y;
    --X; --Y;
    
    int res = 0;
    while (X != Y) {
        X = X >> 1;
        Y = Y >> 1;
        res++;
    }
    cout << res << '\n';
    return 0;
}
