#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 10000;
bool isPrime[MAX];
vector<int> primes;
vector<int> amazingPrimes;

bool IsPrime(int K) {
    if (K < 0) return false;
    else if (K < MAX) return isPrime[K];

    int to = floor(sqrt(K));
    for (int p : primes) {
        if (p > to) break;
        if (K % p == 0) return false;
    }

    return true;
}

void Sieve() {
    primes.clear();
    fill(isPrime, isPrime + MAX, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 0; i < MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i+i; j < MAX; j += i) { isPrime[j] = false; }
    }

    for (int i = 0; i < MAX; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

void BFS(int N) {
    vector<int> smallPrimes = { 2, 3, 5, 7 };
    queue<pair<int,int>> q;

    for (int p : smallPrimes) { q.push({ p, 1 }); }

    while (!q.empty()) {
        int x = q.front().first;
        int len = q.front().second;
        q.pop();

        if (len == N) { 
            amazingPrimes.push_back(x); 
            continue; 
        }

        for (int y : { 1, 3, 7, 9 }) {
            int next = 10*x + y;
            if (IsPrime(next)) q.push({ next, len+1 });
        }
    }
}

int main() {
    cin >> N;
    Sieve();
    BFS(N);
    sort(amazingPrimes.begin(), amazingPrimes.end());
    for (int p : amazingPrimes) cout << p << '\n';

    return 0;
}
