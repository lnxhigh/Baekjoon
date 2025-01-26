#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 300005;

int64 N, S;
pair<int64,int64> A[MAX];
int64 D[MAX];

int64 dfs(int64 x) {
    if (x < 0) return 0;
    else if (D[x]) return D[x];

    int nxt = -1;
    int low = 0, high = x - 1;
    auto [H, C] = A[x];

    while (low <= high) {
        int mid = (low + high) / 2;
        auto [height, _] = A[mid];
        if (height <= H - S) nxt = mid, low = mid + 1;
        else high = mid - 1;
    }

    return D[x] = max(dfs(x - 1), dfs(nxt) + C);
}

int main() {
    FastIO
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int64 H, C; cin >> H >> C;
        A[i] = { H, C };
    }
    sort(A, A + N);

    int64 ans = dfs(N - 1);
    cout << ans << '\n';
    return 0;
}
