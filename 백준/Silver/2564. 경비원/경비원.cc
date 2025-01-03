#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 7;

int W, H;
int N;
int A[MAX];

int main() {
    FastIO
    cin >> W >> H;
    cin >> N;

    for (int i = 0; i <= N; i++) {
        int dir, x; cin >> dir >> x;
        if (dir == 2) A[i] = x;
        else if (dir == 4) A[i] = W + (H - x);
        else if (dir == 1) A[i] = W + H + (W - x);
        else if (dir == 3) A[i] = W + H + W + x;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int dist = 1 << 20;
        
        for (int k = -2; k <= 2; k++) {
            int x = A[N] + k * 2 * (H + W);
            dist = min(dist, abs(x - A[i]));
        }
        ans += dist;
    }

    cout << ans << '\n';
    return 0;
}
