#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int K;
int TC;

bool solve(int M, int N) {
    if (M > N) N++;
    int R = K - max(M, N);
    int D = abs(M - N);
    return D <= R + 1;
}

int main() {
    FastIO

    cin >> K;
    cin >> TC;
    while (TC--) {
        int M, N;
        cin >> M >> N;
        cout << solve(M, N) << '\n';
    }

    return 0;
}
