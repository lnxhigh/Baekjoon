#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1500;

int N, Day;
int X[MAX], Y[MAX];

int main() {
    FastIO
    cin >> N >> Day;
    for (int i = 0; i < Day; i++) {
        int a, b, c; cin >> a >> b >> c;
        X[a]++, Y[2 * N - c]++;
    }

    X[0] = 0, Y[N << 1] = 0;
    for (int i = 1; i < 2 * N; i++) X[i] += X[i - 1];
    for (int i = 1; i < 2 * N; i++) Y[i] += Y[i - 1];

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int idx = (c == 0) ? N - r : N + c;
            
            int zero = X[2 * N - 1] - X[idx - 1];
            int two = Y[idx];
            int one = Day - (zero + two);

            int cnt = one + (two * 2);
            cout << ++cnt << ' ';
        }
        cout << '\n';
    }

    return 0;
}
