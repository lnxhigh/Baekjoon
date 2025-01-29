#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 1 << 10;

int64 N;
bool A[MAX][MAX];
int64 D[MAX][2];

void input() {
    memset(A, false, sizeof(A));
    memset(D, 0, sizeof(D));
    
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            bool flag; cin >> flag;
            A[i][j] = A[j][i] = flag;
            D[i][flag]++, D[j][flag]++;
        }
    }
}

int64 solve() {
    int64 all = N * (N - 1) * (N - 2) / 6;
    int64 sum = 0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (i == j) continue;
            bool flag = A[i][j];
            int64 cnt = D[i][!flag] + D[j][!flag];
            sum += cnt;
        }
    }
    sum /= 4;

    return all - sum;
}

int main() {
    FastIO
    int64 T; cin >> T;
    while (T--) {
        input();
        int64 ans = solve();
        cout << ans << '\n';
    }

    return 0;
}
