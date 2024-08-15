#include <bits/stdc++.h>
using namespace std;

int A, B;
const int MAX = 1 << 14;
bool isPrime[MAX];

void sieve(int N) {
    fill(isPrime, isPrime + MAX, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 0; i <= N; i++) {
        if (!isPrime[i]) continue;
        for (int j = i+i; j <= N; j += i) {
            isPrime[j] = false;
        }
    }
}

int main() {
    cin >> A >> B;
    sieve(B);

    int sum = 0;
    int minPrime = -1;
    bool found = false;

    for (int p = A; p <= B; p++) {
        if (isPrime[p]) {
            sum += p;
            
            if (!found) {
                found = true;
                minPrime = p;
            }
        }
    }

    if (!found) cout << -1 << '\n';
    else cout << sum << '\n' << minPrime << '\n';

    return 0;
}
