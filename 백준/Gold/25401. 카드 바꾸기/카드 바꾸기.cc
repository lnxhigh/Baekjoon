#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 9;

int N;
int X[MAX];

int f(int i, int j) {
    if (i >= j) return N;
    else if ((X[j] - X[i]) % (j - i) != 0) return N;

    int cnt = 0;
    int r = (X[j] - X[i]) / (j - i);

    for (int k = 0; k < N; k++) {
        if (X[i] - X[k] != r * (i - k)) cnt++;
    }
    return cnt;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    int ans = N;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int cnt = f(i, j);
            ans = min(ans, cnt);
        }
    }

    cout << ans << '\n';
    return 0;
}
