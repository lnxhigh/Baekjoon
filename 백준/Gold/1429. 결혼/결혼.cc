#include <bits/stdc++.h>
using namespace std;
const int MAX = 12;

int r, c;
bool arr[MAX][MAX];

int male[MAX];
int female[MAX];

int match[2][1 << MAX];
int bitcount[1 << MAX];

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char x; cin >> x;
            if (x == '1') male[i] |= (1 << j), female[j] |= (1 << i);
        }
    }

    for (int i = 0; i < (1 << r); i++) {
        for (int j = 0; j < r; j++) {
            if (i >> j & 1) match[0][i] |= male[j];
        }
    }

    for (int i = 0; i < (1 << c); i++) {
        for (int j = 0; j < c; j++) {
            if (i >> j & 1) match[1][i] |= female[j];
        }
    }

    int ans = -1;
    bool flag = false;

    for (int i = 0; i < r; i++) {
        if (male[i] == 0) flag = true;
    }
    for (int j = 0; j < c; j++) {
        if (female[j] == 0) flag = true;
    }

    if (flag) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < (1 << max(r, c)); i++) {
        bitcount[i] = __builtin_popcount(i);
    }

    for (int i = 0; i < (1 << r); i++) {
        for (int j = 0; j < (1 << c); j++) {
            int x = i | match[1][j];
            int y = j | match[0][i];
            if (x + 1 != (1 << r) || y + 1 != (1 << c)) continue;

            int cnt = bitcount[i] + bitcount[j];
            if (ans == -1) ans = cnt;
            else ans = min(ans, cnt);
        }
    }

    cout << ans << '\n';
    return 0;
}
