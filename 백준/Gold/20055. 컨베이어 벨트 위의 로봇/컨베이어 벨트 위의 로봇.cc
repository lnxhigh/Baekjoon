#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 11;

int N, K;
int A[MAX];
bool X[MAX];

void input() {
    cin >> N >> K;
    for (int i = 0; i < (N << 1); i++) {
        cin >> A[i];
    }
}

int solve() {
    int cnt = 0;
    int idx = 0;
    int level = 0;
    
    while (cnt < K) {
        level++;

        // Rotate
        for (int i = N - 1; i >= 0; i--) {
            if (!X[i]) continue;
            X[i + 1] = true, X[i] = false;
            X[N - 1] = false;
        }

        if (idx) idx--;
        else idx = (N << 1) - 1;

        // Move
        for (int i = N - 1; i >= 0; i--) {
            if (!X[i]) continue;
            
            int cur = (idx + i) % (N << 1);
            int nxt = (cur + 1) % (N << 1);
            if (X[i + 1] || A[nxt] == 0) continue;

            if (--A[nxt] == 0) cnt++;
            X[i + 1] = true, X[i] = false;
            X[N - 1] = false;
        }

        // New robot
        if (A[idx]) {
            if (--A[idx] == 0) cnt++;
            X[0] = true;
        }
    }

    return level;
}

int main() {
    FastIO
    input();
    cout << solve() << '\n';
    return 0;
}
