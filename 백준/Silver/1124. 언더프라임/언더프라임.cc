#include <bits/stdc++.h>
using namespace std;

int A, B;
const int MAX = 100001;
bool isPrime[MAX];

int f(int X) {
    int res = 0;
    for (int i = 2; i <= X; i++) {
        if (isPrime[X]) break;
        while (X % i == 0) {
            if (X == 1) break;
            res++;
            X /= i;
        }
    }

    if (isPrime[X]) res++;
    return res;
}

void sieve(int N) {
    isPrime[0] = isPrime[1] = false;

    for (int i = 0; i < N; i++) {
        if (!isPrime[i]) continue;
        for (int j = i + i; j < N; j = j + i) {
            isPrime[j] = false;
        }
    }
}

int main() {
    int res = 0;
    cin >> A >> B;
    fill(isPrime, isPrime + MAX, true);
    sieve(MAX);
    for (int i = A; i <= B; i++) if (isPrime[f(i)]) res++;
    cout << res << '\n';
    return 0;
}
