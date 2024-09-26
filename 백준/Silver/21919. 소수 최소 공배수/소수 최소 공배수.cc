#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

const int MAX = 1 << 20;
bool isPrime[MAX];
unordered_set<int64> P;

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

    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        int X; cin >> X;
        if (isPrime[X]) P.insert(X);
    }

    int64 mul = 1;
    if (P.empty()) mul = -1;
    else for (int64 p : P) mul *= p;
    
    cout << mul << '\n';
    return 0;
}
