#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void solve(int N) {
    if (N == 1) { cout << 1 << '\n'; return; }
    if (N &  1) { cout << -1 << '\n'; return; }
    for (int i = 0; i < N / 2; i++) { cout << N - i * 2 << ' ' << i * 2 + 1 << ' '; }
}   

int main() {
    FastIO
    int N; cin >> N;
    solve(N);
    return 0;
}
