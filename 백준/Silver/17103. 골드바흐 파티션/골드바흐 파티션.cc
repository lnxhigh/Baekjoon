#include <bits/stdc++.h>
#define N_MAX 1000001
using namespace std;

int T;
bool isPrime[N_MAX];
vector<int> primes;

int partition(int N) {
    int res = 0;
    int M = N >> 1;
    for (int prime : primes) {
        if (prime > M) break;
        if (isPrime[N - prime]) res++;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    fill(isPrime, isPrime + N_MAX, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 0; i < N_MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i << 1; j < N_MAX; j = j + i) {
            isPrime[j] = false;
        }
    }

    for (int i = 0; i < N_MAX; i++) {
        if (isPrime[i]) primes.push_back(i);
    }

    while (T--) {
        int N;
        cin >> N;
        cout << partition(N) << "\n";
    }
    
    return 0;
}
