#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 10001;

int N;
int D[MAX];

int dfs(int x) {
    if (D[x]) return D[x];

    int ret = N;
    int half = x / 2;
    int sq = sqrt(x);

    for (int i = 1; i <= half; i++) {
        ret = min(ret, dfs(i) + dfs(x - i));
    }
    for (int i = 2; i <= sq; i++) {
        if (x % i == 0) {
            ret = min(ret, dfs(i) + dfs(x / i));
        }
    }

    return D[x] = ret;
}

int main() {
    FastIO
    cin >> N;

    D[1] = 1, D[2] = 2, D[6] = 3;
    D[24] = 4, D[120] = 5, D[720] = 3, D[5040] = 4;

    int ans = dfs(N);
    cout << ans << '\n';
    return 0;
}
