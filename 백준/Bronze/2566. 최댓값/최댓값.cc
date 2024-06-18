#include <bits/stdc++.h>
using namespace std;

const int N = 9;
int Nums[N][N];

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Nums[i][j];
        }
    }

    int res = -1;
    pair<int,int> loc;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (res < Nums[i][j]) {
                res = Nums[i][j];
                loc = { i, j };
            }
        }
    }

    cout << res << '\n';
    cout << loc.first + 1 << ' ' << loc.second + 1 << '\n';
    return 0;
}
