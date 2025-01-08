#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int N, L;
bool D[MAX << 1];

int main() {
    FastIO
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int X; cin >> X;
        D[X] = true;
    }

    int cnt = 0;
    for (int i = 0; i < MAX; i++) {
        if (!D[i]) continue;

        cnt++;
        for (int k = 0; k < L; k++) {
            D[i + k] = false;
        }
    }

    cout << cnt << '\n';
    return 0;
}
