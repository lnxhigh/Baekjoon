#include <bits/stdc++.h>
using namespace std;
const int MAX = 12;

int r, c;
bool arr[MAX][MAX];

bool check(int x, int y) {
    int male = 0;
    int female = 0;

    for (int i = 0; i < r; i++) {
        if ((x >> i & 1) == 0) continue;

        for (int j = 0; j < c; j++) {
            if (arr[i][j]) {
                male |= (1 << i);
                female |= (1 << j);
            }
        }
    }

    for (int i = 0; i < c; i++) {
        if ((y >> i & 1) == 0) continue;

        for (int j = 0; j < r; j++) {
            if (arr[j][i]) {
                male |= (1 << j);
                female |= (1 << i);
            }
        }
    }

    return (male + 1) == (1 << r) && (female + 1) == (1 << c);
}

int get(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        if (x >> i & 1) cnt++;
    }
    for (int i = 0; i < c; i++) {
        if (y >> i & 1) cnt++;
    }

    return cnt;
}

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char x; cin >> x;
            arr[i][j] = (x == '1');
        }
    }

    int ans = -1;

    for (int i = 0; i < (1 << r); i++) {
        for (int j = 0; j < (1 << c); j++) {
            if (!check(i, j)) continue;
            
            int cnt = get(i, j);
            if (ans == -1) ans = cnt;
            else ans = min(ans, cnt);
        }
    }

    cout << ans << '\n';
    return 0;
}
