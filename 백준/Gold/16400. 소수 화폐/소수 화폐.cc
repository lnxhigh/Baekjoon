#include <bits/stdc++.h>
using namespace std;

int N, K;
const int MAX = 40001;
bool isPrime[MAX];
vector<int> P;
long long D[MAX];
const long long DIV = 123456789LL;

void sieve(int N) {
    fill(isPrime, isPrime + N, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 0; i < N; i++) {
        if (!isPrime[i]) continue;
        for (int j = i + i; j < N; j += i) {
            isPrime[j] = false;
        }
    }

    P.clear();
    for (int i = 0; i < N; i++) {
        if (isPrime[i]) P.push_back(i);
    }
    return;
}

int main() {
    cin >> K;
    sieve(K + 1);
    N = P.size();

    D[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int k = P[i]; k <= K; k++) {
            D[k] += D[k - P[i]];
            D[k] %= DIV;
        }
    }
    
    cout << D[K] << '\n';
    return 0;
}
