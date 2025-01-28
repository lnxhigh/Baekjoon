#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 1 << 8;

int64 N;
bool A[MAX][MAX];
int64 D[MAX][MAX];

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (x == y || !A[i][x] || !A[i][y]) continue;
                D[x][y]++;
            }
        }
    }

    int64 cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (x == y || !A[i][x] || !A[i][y]) continue;
                cnt += D[x][y] - 1;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}
