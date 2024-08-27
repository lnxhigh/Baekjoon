#include <bits/stdc++.h>
using namespace std;

string f(int x, int b) {
    if (x < 0 && b > 0) return "-" + f(-x, b);

    if (x >= 0 && x < abs(b)) return to_string(x);
    
    for (int i = 0; i < abs(b); i++) {
        if ((x - i) % b == 0) {
            x = (x - i) / b;
            return f(x, b) + to_string(i);
        }
    }
}

int main() {
    int x; cin >> x;
    int b; cin >> b;
    cout << f(x, b) << '\n';
    return 0;
}
