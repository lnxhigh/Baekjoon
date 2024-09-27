#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 1 << 20;

bool isPrime[MAX];
vector<int64> factors[MAX];
int64 D[MAX];

void sieve() {
    fill(isPrime, isPrime + MAX, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int64 i = 0; i < MAX; i++) {
        if (!isPrime[i]) continue;
        factors[i].push_back(i);
        for (int64 j = i+i; j < MAX; j += i) {
            factors[j].push_back(i);
            isPrime[j] = false;
        }
    }
}

int64 f(int64 x) {
    int64 res = 1;
    for (int64 p : factors[x]) {
        int64 sum = 1, mul = 1; 
        while (x % p == 0) {
            mul *= p;
            sum += mul;
            x /= p;
        }

        res *= sum;
    }

    return res;
}

int main() {
    FastIO
    int T; cin >> T;
    
    sieve();
    for (int i = 1; i < MAX; i++) {
        D[i] = D[i-1] + f(i);
    }

    while (T--) {
        int N; cin >> N;
        cout << D[N] << '\n';
    }
    
    return 0;
}
