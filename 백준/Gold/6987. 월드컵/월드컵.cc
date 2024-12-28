#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int A[6][3];

void input() {
    for (int i = 0; i < 6; i++) {
        for (int k = 0; k < 3; k++) {
            cin >> A[i][k];
        }
    }
}

bool dfs(int i, int j) {
    if (i >= 5) {
        for (int i = 0; i < 6; i++) {
            for (int k = 0; k < 3; k++) {
                if (A[i][k] != 0) return false;
            }
        }
        return true;
    }
    
    int nxti = i, nxtj = j + 1;
    if (nxtj >= 6) nxti = i + 1, nxtj = i + 2;

    for (int k = 0; k < 3; k++) {
        if (A[i][k] > 0 && A[j][2 - k] > 0) {
            A[i][k]--, A[j][2 - k]--;
            if (dfs(nxti, nxtj)) return true;
            A[i][k]++, A[j][2 - k]++;
        }
    }

    return false;
}

int main() {
    FastIO
    int T = 4;
    while (T--) {
        input();
        bool ans = dfs(0, 1);
        cout << ans << ' ';
    }
    cout << '\n';

    return 0;
}
