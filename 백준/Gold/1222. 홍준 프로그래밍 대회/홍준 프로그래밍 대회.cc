#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 21;

int N;
int S[MAX], D[MAX];

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        S[x]++;
    }

    D[1] = N;
    
    for (int i = 2; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
            D[i] += S[j];
        }
    }

    long long ans = N;

    for (int i = 1; i < MAX; i++) {
        if (D[i] <= 1) continue;
        long long cnt = (long long) i * D[i];
        ans = max(ans, cnt);
    }

    cout << ans << '\n';
    return 0;
}
