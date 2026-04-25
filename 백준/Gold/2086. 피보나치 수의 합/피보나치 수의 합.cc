#include <iostream>
#include <map>
#define ll long long
#define K 1000000000LL

using namespace std;

ll a, b;
map<ll,ll> memory;

ll fibonacci(ll N) {
    if (memory.count(N)) return memory[N];

    if (N % 2LL == 0) {
        ll odd = fibonacci(N / 2LL - 1LL);
        ll even = fibonacci(N / 2LL);
        memory[N] = ( ( ( odd + odd + even ) % K ) * even ) % K;
    }
    else {
        ll odd = fibonacci((N-1LL) / 2LL);
        ll even = fibonacci((N+1LL) / 2LL);
        memory[N] = ( (even * even) % K + (odd * odd) % K ) % K;
    }
    
    return memory[N];
}

int main() {
    cin >> a >> b;
    memory[0LL] = 0LL;
    memory[1LL] = 1LL;

    int ans = fibonacci(b+2) - fibonacci(a+1);
    if (ans < 0) ans += K;
    cout << ans;
}