#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime;

vector<int> sieve(int N) {
    vector<int> res;
    isPrime.resize(N+1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 0; i <= N; i++) {
        if (!isPrime[i]) continue;
        for (int j = i+i; j <= N; j += i) {
            isPrime[j] = false;
        }
    }

    for (int i = 0; i <= N; i++) {
        if (isPrime[i]) res.push_back(i);
    }

    return res;
}

vector<int> decompose(int N, const vector<int> &primes) {
    vector<int> res;
    if (N < 8) return res;
    
    N -= 2;
    res.push_back(2);

    int x = (N % 2 == 0) ? 2 : 3;
    N -= x;
    res.push_back(x); 
    
    for (int p : primes) {
        if (p > N) break;
        
        if (isPrime[N-p]) {
            res.push_back(p);
            res.push_back(N-p);
            break;
        }
    }

    sort(res.begin(), res.end());
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<int> primes = sieve(N);
    vector<int> res = decompose(N, primes);

    if (res.empty() || (int) res.size() < 4) cout << -1;
    else for (int p : res) cout << p << ' ';
    cout << '\n';
    return 0;
}
