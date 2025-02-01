#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int N;
bool D[MAX];

char query(int i, int j, char op) {
    cout << '?' << ' ';
    cout << i << ' ' << op << ' ' << j << endl;
    char x; cin >> x;
    return x;
}

void answer() {
    cout << '!' << ' ';
    for (int i = 1; i <= N; i++) {
        char x = D[i] ? '+' : '-';
        cout << x << ' ';
    }
    cout << endl;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 1; i < N; i++) {
        char x = query(i, i + 1, '*');
        if (x == '+') D[i + 1] = D[i];
        else if (x == '-') D[i + 1] = !D[i];
        else assert(false);
    }

    int x = 1, y = -1;
    for (int i = 2; i <= N; i++) {
        if (!(D[x] ^ D[i])) { y = i; break; }
    }
    if (y == -1) { x = 2, y = 3; }
    
    char c = query(x, y, '+');
    if ((c == '+') ^ D[x]) {
        for (int i = 1; i <= N; i++) D[i] ^= true;
    }
    answer();

    return 0;
}
