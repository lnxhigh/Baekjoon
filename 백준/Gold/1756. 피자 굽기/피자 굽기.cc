#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 300001;
const int INF = 1 << 30;

int D, N;
int R[MAX];

int main() {
    FastIO
    cin >> D >> N;

    int x = INF;
    for (int i = 1; i <= D; i++) {
        int r; cin >> r;
        x = min(x, r);
        R[i] = x;
    }

    int top = D, cnt = 0;
    for (int i = 0; i < N; i++) {
        int r; cin >> r;
        while (top && r > R[top]) top--;
        if (!top) continue;
        top--, cnt++;
    }

    int ans = (cnt >= N) ? top + 1 : 0;
    cout << ans << '\n';
    return 0;
}
