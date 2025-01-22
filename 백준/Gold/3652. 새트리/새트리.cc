#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

string f(int x, int y) {
    if (x < y) return "L" + f(y - x, x);
    else if (x > y) return "R" + f(y, x - y);
    return "";
}

int main() {
    FastIO
    string S; cin >> S;

    int k = S.find('/');
    int X = stoi(S.substr(0, k));
    int Y = stoi(S.substr(k + 1));
    
    cout << f(X, Y) << '\n';
    return 0;
}
