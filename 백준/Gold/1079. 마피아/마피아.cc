#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 4;
const int INF = 1 << 30;

int N;
int X[MAX];
int R[MAX][MAX];
int mafia;

bool dead[MAX];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) {
            cin >> R[i][j];
        }
    }
    cin >> mafia;
}

int day() {
    int maxIdx = -1;
    int maxVal = -INF;

    for (int i = 0; i < N; i++) {
        if (dead[i]) {
            continue;
        }
        if (maxVal < X[i]) {
            maxVal = X[i];
            maxIdx = i;
        }
    }
    
    assert(maxIdx >= 0);
    return maxIdx;
}

void night(int killed, bool forward) {
    dead[killed] = forward;
    int sign = forward ? 1 : -1;

    for (int j = 0; j < N; j++) {
        X[j] += sign * R[killed][j];
    }
}

int dfs(int n) {
    // Assume we spend night and day all at once
    assert(n % 2 == 0);
    
    // The game is over if the mafia is dead or alive alone
    if (n == 0 || dead[mafia]) return 0;

    // How many nights can the mafia spend
    int ret = 0;

    // kill
    for (int i = 0; i < N; i++) {
        if (dead[i] || i == mafia) continue;
        
        // Spend night
        night(i, true);
        
        // Spend day
        int killed = day();
        dead[killed] = true;

        // Recursion
        ret = max(ret, dfs(n - 2));

        // Restore
        dead[killed] = false;
        night(i, false);
    }

    // Mafia spend today!
    return ++ret;
}

int solve() {
    int cnt = N;
    if (cnt & 1) {
        int killed = day();
        dead[killed] = true;
        --cnt;
    }

    return dfs(cnt);
}

int main() {
    FastIO
    input();
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
