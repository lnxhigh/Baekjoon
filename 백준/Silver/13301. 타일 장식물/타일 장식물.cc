#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
int64 D[100];

int main() {
    int N; cin >> N;
    D[1] = D[2] = 1;
    for (int i = 2; i <= N; i++) {
        D[i] = D[i-1] + D[i-2];
    }

    int64 ans = D[N] * 4 + D[N-1] * 2;
    cout << ans << '\n';
    return 0;
}
