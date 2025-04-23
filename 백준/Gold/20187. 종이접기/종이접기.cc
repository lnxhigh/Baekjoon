#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int k, hole, len;
string str;

int f(int x, int y, int h, int w) {
    if (h + w == len) return 2 * x + y;

    int ret = -1;
    char c = str[h + w];
    int mx = 0, my = 0;

    if      (c == 'D') mx = max(x, (1 << (k + 1 - h)) - 1 - x) - (1 << (k - h)), my = y, h++;
    else if (c == 'U') mx = min(x, (1 << (k + 1 - h)) - 1 - x), my = y, h++;
    else if (c == 'L') mx = x, my = min(y, (1 << (k + 1 - w)) - 1 - y), w++;
    else if (c == 'R') mx = x, my = max(y, (1 << (k + 1 - w)) - 1 - y) - (1 << (k - w)), w++;

    return f(mx, my, h, w);
}

int main() {
    FastIO
    cin >> k;

    len = k * 2;
    str.resize(len);
    for (auto &c : str) cin >> c;
    cin >> hole;

    int n = (1 << k) * 2;
    
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < n; j += 2) {
            int target = -1;
            bool found = false;

            for (int k = 0; k < 4 && !found; k++) {
                int r = i + k / 2;
                int c = j + k % 2;
                
                if (f(r, c, 0, 0) == hole) {
                    target = k;
                    found = true;
                }
            }

            cout << target << ' ';
        }
        cout << '\n';
    }

    return 0;
}
