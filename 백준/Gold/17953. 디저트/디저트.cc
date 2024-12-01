#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[11][100001];
int D[11][100001];

int dfs(int k, int day) {
    if (D[k][day] != -1) return D[k][day];
    else if (day == 0) return A[k][day];

    int ret = 0;
    for (int i = 0; i < M; i++) {
        int value = A[k][day];
        if (i == k) value /= 2;
        ret = max(ret, dfs(i, day - 1) + value);
    }

    return D[k][day] = ret;
}

int main() {
    cin >> N >> M;
    memset(D, -1, sizeof(D));
    for (int i = 0; i < M; i++) {
        for (int day = 0; day < N; day++) {
            cin >> A[i][day];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < M; i++) {
        ans = max(ans, dfs(i, N - 1));
    }
    cout << ans << '\n';

    return 0;
}
