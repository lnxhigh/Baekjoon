#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

bool play(int x, int y, bool turn) {
    if (x < y) swap(x, y);
    if (x == 0 || y == 0) return !turn;
    
    if (x / y > 1) return turn;
    return play(y, x % y, !turn);
}

int main() {
    FastIO
    while (true) {
        int x, y; cin >> x >> y;
        if (!x && !y) break;
        char winner = play(x, y, true) ? 'A' : 'B';
        cout << winner << " wins\n";
    }
    return 0;
}
