#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

const int MAX = 1 << 20;
bool isPrime[MAX];
vector<int> primes;

pair<int,int> solve(int N) {
    for (int p : primes) {
        if (isPrime[N-p]) return { p, N - p };
    }
    return { 0, 0 };
}

int main() {
    FastIO

    fill(isPrime, isPrime + MAX, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 0; i < MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i+i; j < MAX; j += i) {
            isPrime[j] = false;
        }
    }

    for (int i = 3; i < MAX; i++) {
        if (isPrime[i]) primes.push_back(i);
    }

    while (true) {
        int N; cin >> N;
        assert(~N & 1);
        if (!N) break;

        auto [ x, y ] = solve(N);
        if (x == 0 && y == 0) cout << "Goldbach's conjecture is wrong." << "\n";
        else cout << N << " = " << x << " + " << y << "\n";
    }

    return 0;
}
