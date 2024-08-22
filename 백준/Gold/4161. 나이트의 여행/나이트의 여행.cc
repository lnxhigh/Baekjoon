#include <bits/stdc++.h>
using namespace std;

int cache[4][4] = {
    { 0, 3, 2, 3 },
    { 3, 2, 1, 2 },
    { 2, 1, 4, 3 },
    { 3, 2, 3, 2 }
};

int solve(int X, int Y) {
    X = abs(X), Y = abs(Y);
    if (X < 4 && Y < 4) return cache[X][Y];

    int res = 1 << 30;
    for (int dX = 0; dX < 4; dX++) {
        for (int dY = 0; dY < 4; dY++) {
            int cnt = cache[dX][dY];
            int i = abs(X - dX), j = abs(Y - dY);

            if (2 * i < j) { 
                if ((j + 2*i) % 4 != 0 || (j - 2*i) % 4 != 0) continue;
                int a = (j + 2*i) / 4, b = (j - 2*i) / 4;
                cnt += abs(a) + abs(b);
            }
            else if (2 * j < i) {
                if ((i + 2*j) % 4 != 0 || (i - 2*j) % 4 != 0) continue;
                int a = (i + 2*j) / 4, b = (i - 2*j) / 4;
                cnt += abs(a) + abs(b);
            }
            else {
                if ((i + j) % 3 != 0) continue;
                int s = (i + j) / 3;
                int a = i - s, b = j - s;
                cnt += abs(a) + abs(b);
            }

            res = min(res, cnt);
        }
    }

    return res;
}

int main() {
    while (true) {
        string S;
        cin >> S;
        if (S == "END") break;

        int X = stoi(S), Y;
        cin >> Y;

        int res = solve(X, Y);
        cout << res << '\n';
    }

    return 0;
}
