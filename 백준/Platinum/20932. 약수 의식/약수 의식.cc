#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 1 << 4;

int N;
int A[MAX];
ll D[1 << MAX][MAX][10];

int nums[10];
int visited[10];

ll dfs(int cur, int idx, int rem) {
    if (cur == 0) return (rem == 0);
    else if (D[cur][idx][rem] != -1) return D[cur][idx][rem];

    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        if (!(cur >> i & 1)) continue;

        int nxt = cur & (~(1 << i));
        for (int r = 0; r < A[idx]; r++) {
            if ((10 * r + A[i]) % A[idx] == rem) {
                cnt += dfs(nxt, idx, r);
            }
        }
    }

    return D[cur][idx][rem] = cnt;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        A[i] = x, nums[x]++;
    }

    double ans = 0;
    memset(D, -1, sizeof(D));

    for (int i = 0; i < N; i++) {
        int x = A[i];
        if (visited[x]++) continue;
        int bits = ((1 << N) - 1) & (~(1 << i));
        ans += dfs(bits, i, 0) * nums[x];
    }

    for (int i = 1; i <= N; i++) {
        ans /= i;
    }

    cout << setprecision(16);
    cout << ans << '\n';
    return 0;
}
