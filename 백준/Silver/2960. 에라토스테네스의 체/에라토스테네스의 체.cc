#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 10;
bool isPrime[MAX];

int sieve(int N, int K) {
    int cnt = 0;
    for (int i = 0; i <= N; i++) {
        if (!isPrime[i]) continue;
        if (++cnt == K) return i;
        for (int j = i+i; j <= N; j += i) {
            if (isPrime[j] && ++cnt == K) return j;
            isPrime[j] = false;
        }
    }

    return 0;
}

int main() {
    int N, K; cin >> N >> K;
    fill(isPrime + 2, isPrime + MAX, true);
    cout << sieve(N, K) << '\n';
    return 0;
}
