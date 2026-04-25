#include <iostream>
#define ll long long
using namespace std;

ll A, B, C;

ll remain(ll A, ll B, ll C) {
    if (B == 1) { return A % C; }

    ll X = remain(A * A % C, B / 2, C);
    if (B % 2 == 0) { return X; }
    else { return A * X % C; }
}

int main(void) {
    cin >> A >> B >> C;
    cout << remain(A, B, C) << '\n';
    return 0;
}
