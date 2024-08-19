#include <bits/stdc++.h>
using namespace std;

string S;
int L;
const char RED = 'R', BLUE = 'B';

int paint(char color) {
    int res = 0;
    bool first = true;
    
    for (char c : S) {
        if (c == color) { if (first) res++; first = false; }
        else { first = true; }
    }

    return ++res;
}

int main() {
    cin >> L >> S;
    cout << min(paint(RED), paint(BLUE)) << '\n';
    return 0;
}
