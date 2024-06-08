#include <bits/stdc++.h>
#define M_MAX 100
using namespace std;

int N, M;
int clause[M_MAX][2];

bool checkClause(int i, int &state) {
    for (int k = 0; k < 2; k++) {
        int x = abs(clause[i][k]) - 1;
        bool tmp = (clause[i][k] > 0) ^ ((state & (1 << x)) > 0);
        if (!tmp) return true;
    }
    return false;
}

bool checkAll(int &state) {
    for (int i = 0; i < M; i++) {
        if (!checkClause(i, state)) return false;
    }
    return true;
}

bool solve() {
    for (int i = 0; i < (1 << N); i++) {
        if (checkAll(i)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> clause[i][0] >> clause[i][1];
    }

    bool res = solve();
    cout << res << '\n';

    return 0;
}
