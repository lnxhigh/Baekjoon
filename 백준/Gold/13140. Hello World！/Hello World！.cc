#include <bits/stdc++.h>
using namespace std;

int N;

pair<int,int> solve(int N) {
    pair<int,int> none = { -1, -1 };

    if (N < 20000 || N >= 200000) return none;

    for (int a = 10000; a <= N - 10000; a++) {
        int b = N - a;
        if (a < 10000 || a >= 100000 || b < 10000 || b >= 100000) continue;

        string x = to_string(a);
        string y = to_string(b);

        if (x[0] == '0' || y[0] == '0') continue;
        if (x[2] != x[3] || x[3] != y[3] || y[3] != x[2] || x[4] != y[1]) continue;
        
        if (x[0] == x[1] || x[0] == x[2] || x[0] == x[4]) continue;
        if (x[0] == y[0] || x[0] == y[2] || x[0] == y[4]) continue;
        if (x[1] == x[2] || x[1] == x[4] || x[1] == y[0] || x[1] == y[2] || x[1] == y[4]) continue;
        if (x[4] == y[0] || x[4] == y[2] || x[4] == y[3] || x[4] == y[4]) continue;
        
        if (y[0] == y[1] || y[0] == y[2] || y[0] == y[3] || y[0] == y[4]) continue;
        if (y[1] == y[2] || y[1] == y[3] || y[1] == y[4]) continue;
        if (y[2] == y[3] || y[2] == y[4] || y[3] == y[4]) continue;

        return { a, b };
    }

    return none;
}

void print(pair<int,int> p) {
    int x = p.first, y = p.second;

    if (x == -1 && y == -1) {
        cout << "No Answer" << '\n';
        return;
    }

    cout << "  " << x << '\n';
    cout << "+ " << y << '\n';
    cout << string(7, '-') << '\n';

    cout << " ";
    if (x + y < 100000) cout << " ";
    cout << x + y << '\n';
    return;
}

int main() {
    cin >> N;
    auto p = solve(N);
    print(p);
    return 0;
}
