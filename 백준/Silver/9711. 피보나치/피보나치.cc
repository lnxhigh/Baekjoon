#include <iostream>
#include <map>
#define ll long long

using namespace std;

ll T, P, Q;

ll fibonacci(ll N, ll K, map<ll,ll> &memory) {
    if (memory.count(N)) return memory[N];

    if (N % 2LL == 0) {
        ll odd = fibonacci(N / 2LL - 1LL, K, memory);
        ll even = fibonacci(N / 2LL, K, memory);
        memory[N] = ( ( ( odd + odd + even ) % K ) * even ) % K;
    }
    else {
        ll odd = fibonacci((N-1LL) / 2LL, K, memory);
        ll even = fibonacci((N+1LL) / 2LL, K, memory);
        memory[N] = ( (even * even) % K + (odd * odd) % K ) % K;
    }
    
    return memory[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> P >> Q;
        map<ll,ll> memory;
        memory[0LL] = 0LL % Q;
        memory[1LL] = 1LL % Q;

        cout << "Case #" << i << ": " << fibonacci(P, Q, memory) << '\n';
    }

    return 0;
}