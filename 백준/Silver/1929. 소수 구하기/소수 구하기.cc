#include <bits/stdc++.h>
#define N_MAX 1000001
using namespace std;

int M, N;
bool isPrime[N_MAX];

int main() {
    cin >> M >> N;

    fill(isPrime, isPrime + N_MAX, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 0; i < N_MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i + i; j < N_MAX; j = j + i) {
            isPrime[j] = false;
        }
    }

    for (int i = M; i <= N; i++) {
        if (isPrime[i]) cout << i << '\n';
    }

    return 0;
}
